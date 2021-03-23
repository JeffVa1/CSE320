/************************************************************************************
	Project 11
	Jeffrey Valentic
	CSE 320
	12/10/2020
************************************************************************************/

	.global search
	.global delete
	.global insert

	.data
q:	.word 0
d:	.word 44

	.text
	.balign 4

search:
	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	
	mov		r4, r1											@ id of student to find 

	mov		r11, r0											@ address to table
	ldrh	r7, [r11, #0]									@ num of items in table
	ldrh	r8, [r11, #2]									@ num of students
	ldr		r9, [r11, #8]									@ address of student 

	mov		r10, #0

	ldrh	r6, [r9, #0]

srchLoop:
	cmp		r10, r8
	bgt		notFound

	cmp		r6, r4
	bgt		notFound

	cmp		r6, r4
	beq		found

	add		r10, #1
	add		r9, #44
	ldrh	r6, [r9, #0]

	bl		srchLoop

notFound:
	mov		r0, #0
	strh	r9, [r2]
	bl		endSearch

found:
	mov		r0, #1
	strh	r9, [r2]
	bl		endSearch

endSearch:
	pop		{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	bx		lr

delete:
	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	
	mov		r4, r0											@ store table in r4
	ldr		r5, [r4, #8]									@ address of student
	ldrh	r6, [r4, #2]									@ num of students
	ldr		r7, =q

	mov		r8, r4
	add		r8, #8
	mov		r2, r8
	bl		search

	ldr		r2, =d

	cmp		r0, #1
	beq		delFound
	cmp		r0, #0
	beq		delNotFound

delFound:
	mov		r11, #44
	mul		r11, r6, r11

	ldr		r10, [r7]
	mov		r0, r10

	add		r5, r11
	sub		r9, r5, r10

	ldr		r1, =q
	ldr		r1, [r1]

	mov		r2, r9
	add		r1, #44		

	sub		r6, #1
	strh	r6, [r4, #2]
	bl		memmove

	mov		r0, #1
	bl		endDelete
	

delNotFound:
	mov		r0, #0
	bl		endDelete

endDelete:
	pop		{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	bx		lr

insert:
	push	{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	pop		{r4, r5, r6, r7, r8, r9, r10, r11, lr}
	bx		lr
