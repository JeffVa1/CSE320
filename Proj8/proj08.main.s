	.global main

	.text
main:	push	{lr}

	mov	r4, #0		@ Char count
	mov	r5, #0		@ New line count
	mov	r6, #0		@ Whitespace count
	mov	r7, #0		@ Letter count (A-Z or a-z)
	mov	r8, #0		@ Decimal digit count (0-9)
	mov	r9, #0		@ Hexidecimal digit count (0-9 or A-F or a-f)
	mov	r10, #0		@ Arithmetic operator count (+, -, *, /)

loop:	bl	getchar 	@ Read in a char

@====================================================================================

ifNL:	cmp	r0, #0x0a	@ If char = new line (0x0A)
	bne	ifSp

thnNL:	add	r4, r4, #1	@ +1 to char count (r4)
	add	r5, r5, #1	@ +1 to new line count (r5)
	add	r6, r6, #1	@ +1 to white space count (r6)

@====================================================================================

ifSp:	cmp	r0, #0x20	@ If char = space (0x20)
	bne	ifTab

thnSp:	add	r4, r4, #1	@ +1 to char count (r4)
	add	r6, r6, #1	@ +1 to white space count (r6)

@====================================================================================

ifTab:	cmp	r0, #0x09	@ If char = tab (0x09)
	bne	ifCap

thnTab:	add	r4, r4, #1	@ +1 to char count (r4)
	add	r6, r6, #1	@ +1 to white space count (r6)

@====================================================================================

ifCap:	cmp	r0, #0x40	@ Compare char to A
	ble	ifLow		@ If char < A, skip
	cmp	r0, #0x5b	@ Compare char to Z
	bge	ifLow		@ If char > Z, skip

thnCap:	add	r4, r4, #1	@ +1 to char count (r4)
	add	r7, r7, #1	@ +1 to letter count

@====================================================================================

ifLow:	cmp	r0, #0x61	@ Compare char to a
	ble	ifDec		@ If char < a, skip
	cmp	r0, #0x7a	@ Compare char to z
	bge	ifDec		@ If char > z, skip

thnLow:	add	r4, r4, #1	@ +1 to char count (r4)
	add	r7, r7, #1	@ +1 to letter count

@====================================================================================

ifDec:	cmp	r0, #0x30	@ Compare char to 0
	ble	hexCap		@ If char < 0, skip
	cmp	r0, #0x39	@ Compare char to 9
	bge	hexCap		@ If char > 9, skip

thnDec:	add	r4, r4, #1	@ +1 to char count (r4)	
	add	r8, r8, #1	@ +1 to decimal digit count
	add	r9, r9, #1	@ +1 to hex count

@====================================================================================

hexCap:	cmp	r0, #0x40	@ Compare char to A
	ble	hexLow		@ If char < A, skip
	cmp	r0, #0x46	@ Compare char to F
	bge	hexLow		@ If char > F, skip

thnHC:	add	r9, r9, #1	@ +1 to hex count

@====================================================================================

hexLow:	cmp	r0, #0x61	@ Compare char to a
	ble	ifAdd		@ If char < a, skip
	cmp	r0, #0x66	@ Compare char to f
	bge	ifAdd		@ If char > f, skip

thnHL:	add	r9, r9, #1	@ +1 to hex count

@====================================================================================

ifAdd:	cmp	r0, #0x2b	@ Compare char to +
	bne	ifSub		@ If char not +, skip

thnAdd:	add	r10, r10, #1	@ +1 to operator count

@====================================================================================

ifSub:	cmp	r0, #0x2d	@ Compare char to -
	bne	ifMul		@ If char not -, skip

thnSub:	add	r10, r10, #1	@ +1 to operator count

@====================================================================================

ifMul:	cmp	r0, #0x2a	@ Compare char to *
	bne	ifDiv		@ If char not *, skip

thnMul:	add	r10, r10, #1	@ +1 to operator count

@====================================================================================

ifDiv:	cmp	r0, #0x2f	@ Compare char to /
	bne	ifEnd		@ If char not /, skip

thnDiv:	add	r10, r10, #1	@ +1 to operator count

@====================================================================================

ifEnd:	cmp	r0, #-1		@ Compare char to -1 (end file)
	beq	end		@ If char = -1, skip to end
	b	loop		@ Else, Restart loop

end:	ldr	r0, =fmt1
	mov	r1, r4
	bl	printf

	ldr	r0, =fmt2
	mov	r1, r5
	bl	printf

	ldr	r0, =fmt3
	mov	r1, r6
	bl	printf

	ldr	r0, =fmt4
	mov	r1, r7
	bl	printf

	ldr	r0, =fmt5
	mov	r1, r8
	bl	printf

	ldr	r0, =fmt6
	mov	r1, r9
	bl	printf

	ldr	r0, =fmt7
	mov	r1, r10
	bl	printf


	pop	{lr}
	bx	lr

@====================================================================================

fmt1:   .asciz  "\n%d Characters found"
fmt2:   .asciz  "\n         New Line Total:\t %d"
fmt3:   .asciz  "\n       Whitespace Total:\t %d"
fmt4:   .asciz  "\n           Letter Total:\t %d"
fmt5:   .asciz  "\n    Decimal Digit Total:\t %d"
fmt6:   .asciz  "\nHexidecimal Digit Total:\t %d"
fmt7:   .asciz  "\n         Operator Total:\t %d"

@====================================================================================