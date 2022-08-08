  ;from scratch fibonacci calculator in masm
	;utilizing labels and secondary functions which is not the most efficent but useful for learning
	;contains a logic bug fixed in the next iteration
	
	option casemap:none
	nl = 10
	.const
	ttlStr	byte	'fib sequence', 0
	fibprint	byte	'next number =%d', nl, 0
	.data
	firstint dword 1
	secondint dword 1
	maxint dword	317811
	
	.code
	externdef printf:proc
	public getTitle
	
	getTitle proc
	
	lea rax, ttlStr
	ret
	
	getTitle endp
	
	public asmMain
	asmMain proc
	sub rsp, 56
	
	
	
	mov r14d, maxint
	jmp nextfibnumber
	
	
	
	
	nextfibnumber:
	mov edx, firstint
	mov ecx, secondint
	mov r15, rdx
	add rdx, rcx
	mov firstint, edx
	mov secondint, r15d
	
	lea rcx, fibprint
	call printf
	mov r15d, firstint
	cmp r15, r14
	jl nextfibnumber
	jge endroutine
	
	endroutine:
	add rsp, 56
	ret
	
	asmMain endp
	
	end
	;rcx, rdx, r8, r9, 
