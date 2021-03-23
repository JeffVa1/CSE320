 
#include "/user/cse320/Projects/project07.hardware.h"
#include <stdbool.h>

unsigned int get_sign_bit(unsigned int operand)
{
    unsigned int sign_bit = (operand & 0x80000000);
    return sign_bit;
}

unsigned int get_c_val()
{
    unsigned int c = ((CPSR & 0x20000000) >> 29);
    return c;
}

unsigned int get_new_z(unsigned int operand)
{
    unsigned int new_z;

    if (operand == 0) {
        new_z = 0x40000000;
    }
    else {
        new_z = 0x00000000;
    }

    return new_z;
}

void execute()
{
    unsigned int leading_bits = ((IR & 0xec000000) >> 26);  
    unsigned int i_bit = ((IR & 0x02000000) >> 25);         //Decides value for operand2
    unsigned int opcode = ((IR & 0x01e00000) >> 21);        //Decides which operation to perform
    unsigned int s_bit = ((IR & 0x00100000) >> 20);         //Decides if you update NZCV 
    unsigned int rn = ((IR & 0x000f0000) >> 16);            //operand A
    unsigned int rd = ((IR & 0x0000f000) >> 12);            //location to store results
    unsigned int immediate_val = (IR & 0x00000ff);          //Operand B     when I = 1
    unsigned int rm = (IR & 0x000000f);                     //Operand B     when I = 0

    unsigned int zeros_i = ((IR & 0x00000f00) >> 8);
    unsigned int zeros = ((IR & 0x00000ff0) >> 4);

    //SETTING UP OPERANDS
    signal32 RN, RM, RD;
    read_reg_file(rn, rm, &RN, &RM);
    
    unsigned int operand1 = RN;
    unsigned int operand2;

    //CHECKING I BIT TO DETERMINE IF OPERAND2 IS immediate_val OR rm
    //CHECKING IR BITS 4-7 IF i_bit = 0
    bool valid_instr;

    if (leading_bits != 0x38) {
        valid_instr = false;
        CPSR = CPSR & 0xfffffffe;
        CPSR = CPSR | 0x00000001;
    }
    else if ((zeros_i != 0 && i_bit == 1) || (zeros != 0 && i_bit == 0)) {
        valid_instr = false;
        CPSR = CPSR & 0xfffffffe;
        CPSR = CPSR | 0x00000001;
    }
    else {
        valid_instr = true;
        CPSR = CPSR & 0xfffffffe;
    }

    if (i_bit == 0) {
        operand2 = RM;
    }
    else {
        operand2 = immediate_val;
    }

    //CHECKING S BIT TO DETERMINE IF NZCV NEEDS TO BE UPDATED
    bool update_nzcv;

    if (s_bit == 1) {
        update_nzcv = true;
    }
    else {
        update_nzcv = false;
    }

    //DECLARING VARIABLES NEEDED FOR OPERATIONS
    unsigned int result;

    unsigned int new_nzcv;
    unsigned int new_c;
    unsigned int new_v;
    unsigned int new_z;
    unsigned int new_n;

    if (valid_instr) {

        unsigned int sign_op1;
        unsigned int sign_op2;
        unsigned int sign_result;
        unsigned int old_c;

    //####################################################################################################################

        switch (opcode)
        {
        case 0x0: //and
            result = operand1 & operand2;

            if (update_nzcv) {
                new_n = get_sign_bit(result);
                new_z = get_new_z(result);
                new_c = 0x00000000;
                new_v = 0x00000000;

                new_nzcv = new_n | new_z | new_c | new_v;

                CPSR = CPSR & 0x0fffffff;
                CPSR = CPSR | new_nzcv;
            }

            RD = result;
            write_reg_file(rd, RD);
            break;

    //####################################################################################################################

        case 0x1: //eor
            result = operand1 ^ operand2;

            if (update_nzcv) {
                new_n = get_sign_bit(result);
                new_z = get_new_z(result);
                new_c = 0x00000000;
                new_v = 0x00000000;

                new_nzcv = new_n | new_z | new_c | new_v;

                CPSR = CPSR & 0x0fffffff;
                CPSR = CPSR | new_nzcv;
            }

            RD = result;
            write_reg_file(rd, RD);
            break;

    //####################################################################################################################

        case 0x2: //sub
            result = operand1 - operand2;

            if (update_nzcv) {
                sign_op1 = get_sign_bit(operand1);
                sign_op2 = get_sign_bit(operand2);
                sign_result = get_sign_bit(result);

                new_n = sign_result;
                new_z = get_new_z(result);
                new_c = ((~sign_op1 & sign_op2) | (sign_result & (~sign_op1 | sign_op2)));

                if (sign_op1 != sign_op2 && sign_result == sign_op2) {
                    new_v = 0x10000000;
                }
                else {
                    new_v = 0x00000000;
                }

                new_nzcv = new_n | new_z | new_c | new_v;

                CPSR = CPSR & 0x0fffffff;
                CPSR = CPSR | new_nzcv;
            }

            RD = result;
            write_reg_file(rd, RD);
            break;

    //####################################################################################################################

        case 0x3: //rsb
            result = operand2 - operand1;

            if (update_nzcv) {
                sign_op1 = get_sign_bit(operand1);
                sign_op2 = get_sign_bit(operand2);
                sign_result = get_sign_bit(result);

                new_n = sign_result;
                new_z = get_new_z(result);
                new_c = ((~sign_op2 & sign_op1) | (sign_result & (~sign_op2 | sign_op1)));

                if (sign_op1 != sign_op2 && sign_result == sign_op1) {
                    new_v = 0x10000000;
                }
                else {
                    new_v = 0x00000000;
                }

                new_nzcv = new_n | new_z | new_c | new_v;

                CPSR = CPSR & 0x0fffffff;
                CPSR = CPSR | new_nzcv;
            }

            RD = result;
            write_reg_file(rd, RD);
            break;

    //####################################################################################################################

        case 0x4: //add
            result = operand1 + operand2;
        
            if (update_nzcv) {
                sign_op1 = get_sign_bit(operand1);
                sign_op2 = get_sign_bit(operand2);
                sign_result = get_sign_bit(result);

                new_n = sign_result;
                new_z = get_new_z(result);
                new_c = ((sign_op1 & sign_op2) | (~sign_result & (sign_op1 | sign_op2)));

                if (sign_op1 == sign_op2 && sign_result != sign_op1) {
                    new_v = 0x10000000;
                }
                else {
                    new_v = 0x00000000;
                }

                new_nzcv = new_n | new_z | new_c | new_v;

                CPSR = CPSR & 0x0fffffff;
                CPSR = CPSR | new_nzcv;
            }

            RD = result;
            write_reg_file(rd, RD);
            break;

    //####################################################################################################################

        case 0x5: //adc         UPDATE NZCV
            old_c = get_c_val();
            result = operand1 + operand2 + old_c;

            sign_op1 = get_sign_bit(operand1);
            sign_op2 = get_sign_bit(operand2);
            sign_result = get_sign_bit(result);

            new_n = sign_result;
            new_z = get_new_z(result);
            new_c = ((sign_op1 & sign_op2) | (~sign_result & (sign_op1 | sign_op2)));

            if (sign_op1 == sign_op2 && sign_result != sign_op1) {
                new_v = 0x10000000;
            }
            else {
                new_v = 0x00000000;
            }

            new_nzcv = new_n | new_z | new_c | new_v;

            CPSR = CPSR & 0x0fffffff;
            CPSR = CPSR | new_nzcv;

            RD = result;
            write_reg_file(rd, RD);
            break;
        
    //####################################################################################################################

        case 0x6: //sbc         UPDATE NZCV
            old_c = get_c_val();
            result = operand1 - operand2 - ~old_c;

            sign_op1 = get_sign_bit(operand1);
            sign_op2 = get_sign_bit(operand2);
            sign_result = get_sign_bit(result);

            new_n = sign_result;
            new_z = get_new_z(result);
            new_c = ((~sign_op1 & sign_op2) | (sign_result & (~sign_op1 | sign_op2)));

            if (sign_op1 != sign_op2 && sign_result == sign_op2) {
                new_v = 0x10000000;
            }
            else {
                new_v = 0x00000000;
            }

            new_nzcv = new_n | new_z | new_c | new_v;

            CPSR = CPSR & 0x0fffffff;
            CPSR = CPSR | new_nzcv;

            RD = result;
            write_reg_file(rd, RD);
            break;

    //####################################################################################################################

        case 0x7: //rsc         UPDATE NZCV
            old_c = get_c_val();
            result = operand2 - operand1 - ~old_c;

            sign_op1 = get_sign_bit(operand1);
            sign_op2 = get_sign_bit(operand2);
            sign_result = get_sign_bit(result);

            new_n = sign_result;
            new_z = get_new_z(result);
            new_c = ((~sign_op2 & sign_op1) | (sign_result & (~sign_op2 | sign_op1)));

            if (sign_op1 != sign_op2 && sign_result == sign_op1) {
                new_v = 0x10000000;
            }
            else {
                new_v = 0x00000000;
            }

            new_nzcv = new_n | new_z | new_c | new_v;

            CPSR = CPSR & 0x0fffffff;
            CPSR = CPSR | new_nzcv;

            RD = result;
            write_reg_file(rd, RD);
            break;

    //####################################################################################################################

        case 0x8: //tst         UPDATE NZ, SET C AND V TO 0         DONT WRITE REG FILE
            result = operand1 & operand2;

            new_n = get_sign_bit(result);
            new_z = get_new_z(result);
            new_c = 0x00000000;
            new_v = 0x00000000;

            new_nzcv = new_n | new_z | new_c | new_v;

            CPSR = CPSR & 0x0fffffff;
            CPSR = CPSR | new_nzcv;
            break;

    //####################################################################################################################

        case 0x9: //teq         UPDATE NZ, SET C AND V TO 0         DONT WRITE REG FILE
            result = operand1 ^ operand2;

            new_n = get_sign_bit(result);
            new_z = get_new_z(result);
            new_c = 0x00000000;
            new_v = 0x00000000;

            new_nzcv = new_n | new_z | new_c | new_v;

            CPSR = CPSR & 0x0fffffff;
            CPSR = CPSR | new_nzcv;
            break;

    //####################################################################################################################

        case 0xa: //cmp         UPDATE NZ, SET C AND V TO 0         DONT WRITE REG FILE
            result = operand1 - operand2;

            new_n = get_sign_bit(result);
            new_z = get_new_z(result);
            new_c = 0x00000000;
            new_v = 0x00000000;

            new_nzcv = new_n | new_z | new_c | new_v;

            CPSR = CPSR & 0x0fffffff;
            CPSR = CPSR | new_nzcv;
            break;
        
    //####################################################################################################################

        case 0xb: //cmn         UPDATE NZ, SET C AND V TO 0         DONT WRITE REG FILE
            result = operand1 + operand2;
        
            new_n = get_sign_bit(result);
            new_z = get_new_z(result);
            new_c = 0x00000000;
            new_v = 0x00000000;

            new_nzcv = new_n | new_z | new_c | new_v;

            CPSR = CPSR & 0x0fffffff;
            CPSR = CPSR | new_nzcv;
            break;

    //####################################################################################################################

        case 0xc: //orr
            result = operand1 | operand2;

            if (update_nzcv) {
                new_n = get_sign_bit(result);
                new_z = get_new_z(result);
                new_c = 0x00000000;
                new_v = 0x00000000;

                new_nzcv = new_n | new_z | new_c | new_v;

                CPSR = CPSR & 0x0fffffff;
                CPSR = CPSR | new_nzcv;
            }

            RD = result;
            write_reg_file(rd, RD);
            break;

    //####################################################################################################################

        case 0xd: //mov
            result = operand2;

            if (update_nzcv) {
                new_n = get_sign_bit(result);
                new_z = get_new_z(result);
                new_c = 0x00000000;
                new_v = 0x00000000;

                new_nzcv = new_n | new_z | new_c | new_v;

                CPSR = CPSR & 0x0fffffff;
                CPSR = CPSR | new_nzcv;
            }

            RD = result;
            write_reg_file(rd, RD);
            break;

    //####################################################################################################################

        case 0xe: //bic
            result = operand1 & ~operand2;

            if (update_nzcv) {
                new_n = get_sign_bit(result);
                new_z = get_new_z(result);
                new_c = 0x00000000;
                new_v = 0x00000000;

                new_nzcv = new_n | new_z | new_c | new_v;

                CPSR = CPSR & 0x0fffffff;
                CPSR = CPSR | new_nzcv;
            }

            RD = result;
            write_reg_file(rd, RD);
            break;

    //####################################################################################################################

        case 0xf: //mvn
            result = ~operand2;

            if (update_nzcv) {
                new_n = get_sign_bit(result);
                new_z = get_new_z(result);
                new_c = 0x00000000;
                new_v = 0x00000000;

                new_nzcv = new_n | new_z | new_c | new_v;

                CPSR = CPSR & 0x0fffffff;
                CPSR = CPSR | new_nzcv;
            }

            RD = result;
            write_reg_file(rd, RD);
            break;

        }

    }

}
