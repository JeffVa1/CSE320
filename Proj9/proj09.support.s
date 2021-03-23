/************************************************************************************
	Project 9
	Jeffrey Valentic
	CSE 320
	11/12/2020
************************************************************************************/

	.global negate
	.global absolute
	
	.global add
	.global sub
	.global mul
	.global divide
	
	.global power
	.global factorial

	.text

@ r8 is being used as the placeholder storage location for return values

negate:
	push    {r4,r5,r6,r7,r8,lr}
	mov	r8, r0				@ move val in r0 to r8

	cmp	r8, #0x80000000			@ compare to biggest negative that has no positive.
	beq	error				@ invalid input -> overflow return

	mov	r4, #0
	subs	r8, r4, r8			@ subtract val from 0

	mov	r0, r8				@ store r8 value in r0
	bl	finished			@ end the program

absolute:
	push    {r4,r5,r6,r7,r8,lr}
	
	mov	r8, r0				@ move val in r0 to r8
	
	cmp	r8, #0x80000000			@ compare to biggest negative that has no positive.
	beq	error	

	cmp	r8, #0x0			@ compare r8 to 0
	blt	makePos				@ if r8 < 0, go to makePos
	
	bl	absFinal			@ else, return the abs

makePos:
	mov	r4, #0
	subs	r8, r4, r8			@ subtract val from 0

absFinal:
	mov	r0, r8				@ store r8 value in r0
	bl	finished			@ end the program

add:
	push    {r4,r5,r6,r7,r8,lr}
	
	mov	r4, r0				@ move val in r0 to r4
	mov	r5, r1				@ move val in r1 to r5

	adds	r8, r4, r5			@ store r4 + r5 into r8
	bvs	error				@ if overflow then go to that function

	mov	r0, r8				@ store value in r8 to r0
	bl	finished			@ end the program

sub:
	push    {r4,r5,r6,r7,r8,lr}
	
	mov	r4, r0				@ move val in r0 to r4
	mov	r5, r1				@ move val in r1 to r5

	subs	r8, r4, r5			@ store r4 - r5 into r8
	bvs	error				@ if overflow then go to that function

	mov	r0, r8				@ store value in r8 to r0
	bl	finished			@ end the program

mul:
	push    {r4,r5,r6,r7,r8,r9,r10,r11,lr}
	
	mov	r4, r0				@ move val in r0 to r4
	mov	r5, r1				@ move val in r1 to r5

	smull	r8, r9, r4, r5			@ signed multiplication between r4 & r5

	cmp	r8, #-1
	ble	negOverflow

	cmp	r8, #0
	bge	posOverflow

posOverflow:
	cmp	r9, #0
	bne	mulOverflow
	bl	mulComplete

negOverflow:
	cmp	r9, #0xffffffff
	bne	mulOverflow
	bl	mulComplete

mulOverflow:
	mov	r8, #0x80000000

mulComplete:
	mov	r0, r8
	pop	{r4,r5,r6,r7,r8,r9,r10,r11,lr}
	bx	lr

divide:
	push    {r4,r5,r6,r7,r8,r9,r10,r11,lr}
	
	mov	r5, r1

	cmp	r5, #0
	beq	divError
	
	mov	r4, r0

	sdiv	r8, r4, r5

	mov	r0, r8

	bl	divComplete

divError:
	mov	r0, #0x80000000

divComplete:
	pop	{r4,r5,r6,r7,r8,r9,r10,r11,lr}
	bx	lr

power:
	push    {r4,r5,r6,r7,r8,lr}

	cmp	r1, #0
	blt	error
	cmp	r1, #0
	beq	expZero
	
	mov	r4, r0
	mov	r8, r0
	mov	r5, r1

expMul:
	cmp	r5, #1
	beq	expComplete

	sub	r5, r5, #1

	mov	r0, r4
	mov	r1, r8
	bl	mul

	mov	r8, r0

	bl	expMul

expZero:
	mov	r0, #1
	bl	finished

expComplete:
	mov	r0, r8
	bl	finished

factorial:
	push	{r4,r5,r6,r7,r8,lr}
	
	mov	r8, r0
	
	cmp	r8, #0x0
	blt	error

	cmp	r8, #0x0
	beq	facZero

	mov	r4, r0
	
	bl	facLoop

facZero:
	mov	r0, #1
	bl	finished

facLoop:
	sub	r4, r4, #1

	cmp	r4, #1
	blt	facComplete
	
	mov	r0, r8
	mov	r1, r4

	bl	mul

	mov	r8, r0

	bl	facLoop

facComplete:
	mov	r0, r8
	bl	finished

error:
	mov	r0, #0x80000000

finished:
	pop	{r4,r5,r6,r7,r8,lr}
	bx	lr
