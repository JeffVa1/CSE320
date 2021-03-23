/************************************************************************************
	Project 10
	Jeffrey Valentic
	CSE 320
	12/3/2020
************************************************************************************/

	.global length
	.global copy
	.global append
	.global duplicate
	.global compare

	.text

	.balign 4

length:
	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	
	ldrb	r4, [r0]
	mov		r5, #0

	cmp		r4, #0
	beq		endLen
	
	bl		lenLoop

lenLoop:
	add		r5, #1

	add		r0, r0, #1
	ldrb	r4, [r0]

	cmp		r4, #0
	beq		endLen

	bl		lenLoop

endLen:
	mov		r0, r5
	pop		{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	bx		lr

copy:
	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	mov		r5, r1
	mov		r4, r0
	ldrb	r6, [r5]

copyLoop:
	cmp		r6, #0
	beq		endCopy

	strb	r6, [r4]

	add		r4, #1
	add		r5, #1

	ldrb	r6, [r5]

	bl		copyLoop

endCopy :
	mov		r11, #0
	strb	r11, [r4]

	pop		{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	bx		lr

append:
	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	
	mov		r4, r0
	mov		r5, r1
	ldrb	r6, [r5]

findDestEnd:
	ldrb	r7, [r4]
	cmp		r7, #0
	beq		appLoop

	add		r4, #1
	bl		findDestEnd

appLoop:
	cmp		r6, #0
	beq		endApp

	strb	r6, [r4]
	add		r4, #1
	add		r5, #1

	ldrb	r6, [r5]
	bl		appLoop

endApp:
	mov		r11, #0
	strb	r11, [r4]

	pop		{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	bx		lr

duplicate:
	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	mov		r10, r0

	bl		length

	bl		malloc

	mov		r2, r0
	mov		r1, r10

	bl		copy
	
endDup:
	mov		r0, r2
	pop		{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	bx		lr

compare:
	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	mov		r10, r0
	mov		r11, r1

compLoop:
	ldrb	r4, [r10]
	ldrb	r5, [r11]

	subs	r6, r4, r5
	cmp		r6, #0
	bne		endComp

	add		r10, #1
	add		r11, #1

	cmp		r4, #0
	beq		checkOther

	bl		compLoop

checkOther:
	cmp		r5, #0
	beq		endComp
	bl		compLoop

endComp:
	mov		r0, r6
	pop		{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	bx		lr
