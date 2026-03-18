; 16-bit Addition
; Add two 16-bit numbers

section .data
    num1 dw 0x1234      ; First 16-bit number
    num2 dw 0x5678      ; Second 16-bit number
    result dw 0         ; Store result

section .text
    global _start

_start:
    ; Load first number into AX
    mov ax, [num1]
    
    ; Add second number to AX
    add ax, [num2]
    
    ; Store result
    mov [result], ax
    
    ; Exit program
    mov eax, 1
    int 0x80