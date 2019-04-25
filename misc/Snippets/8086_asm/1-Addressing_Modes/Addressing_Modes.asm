TITLE   DEMO PROGRAM FOR REGISTER
PAGE    60,132
;-----------------------------------------------------------
STSEG   SEGMENT
        DB 32 DUP (?)
STSEG   ENDS
;-----------------------------------------------------------
DTSEG   SEGMENT
                
DTSEG   ENDS
;-----------------------------------------------------------
CDSEG   SEGMENT

MAIN    PROC FAR        ;entry point
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG

        CALL IMDT       ;(2) Immediate Addressing Mode
        CALL REG        ;(1) Register Addressing Mode
        CALL DIRCT      ;(3) Direct Addressing Mode
        CALL REGID      ;(4) Register Indirect Addressing Mode
        CALL BSDRL      ;(5) Based Relative Addressing Mode
        CALL IDXRL      ;(6) Index Relative Addressing Mode
        CALL BSDID      ;(7) Based Indexed Addressing Mode

        MOV AL,4CH      ;exit syscall
        INT 21H         ;DOS interrupt
MAIN    ENDP

;-----------------------------------------------------------
; 1. Register Addressing Mode
; use registers to hold the data to be manipulated
; <NOTE> memory to memory is never allowed in x86 asm.
; <NOTE> MOV values directly into segment regs isn't allowd.
REG     PROC FAR
        MOV     BX,AX   ;move the content of DX into BX
        RET
REG     ENDP
;-----------------------------------------------------------
; 2. Immediate Addressing Mode
; load data into any registers EXCEPT the segment/flag regs
; <NOTE> segment regs: CS, DS, ES, SS.
IMDT    PROC FAR
        MOV     AX,13H  ;move 13H into AX
        MOV     BL,2FH  ;move 2FH into BL
        RET
IMDT    ENDP
;-----------------------------------------------------------
; 3. Direct Addressing Mode
; move data between memory and registers
; <NOTE> the address of the operand is an offset address.
DIRCT   PROC FAR
;       MOV     [0010],AX       ;ILLEGAL!
        MOV     BX,0010
        MOV     [BX],AX
        MOV     CX,[0010]       ;move contents of DS:0010 into CX
;       MOV     [0016],87H      ;ILLEGAL!
        RET
DIRCT   ENDP
;-----------------------------------------------------------
; 4. Register Indirect Addressing Mode
; the address of the operand is held by a register
; <NOTE> SI, DI, BX --> can be used as pointers.
REGID   PROC FAR
        MOV     SI,0010         ;move address from CX into SI
        MOV     CX,[SI]         ;move contents of DS:SI into CX
        MOV     [SI],BX         ;the content of DS:0010 will be 2FH now
        RET
REGID   ENDP
;-----------------------------------------------------------
; 5. Based Relative Addressing Mode
; base register + displacement value --> effective address
; <NOTE> BX, BP
BSDRL   PROC FAR
        MOV     BX,0010         ;move 0010 into BX
        MOV     CL,[BX+1]       ;move DS:BX+1 into CL
        MOV     CL,[BX]+1       ;same as the above
        MOV     CL,1[BX]        ;same as the above
        MOV     BP,0010         ;move 0010 into BX
        MOV     AL,[BP+1]       ;move SS:BP+1 into AL
        RET
BSDRL   ENDP
;-----------------------------------------------------------
; 6. Index Relative Addressing Mode
; index register + displacement value --> effective address
; <NOTE> SI, DI
IDXRL   PROC FAR
        MOV     SI,0010         ;move 0010 into SI
        MOV     DX,[SI]+6       ;move DS:SI+6 into DX
        MOV     DI,0010         ;move 0010 into DI
;       MOV     AX,[DI]+6       ;AX is NOT allowed!
        RET
IDXRL   ENDP
;-----------------------------------------------------------
; 7. Based Indexed Addressing Mode
; combining 5 and 6. one base reg and one index reg is used
; <NOTE> BX/BP + SI/DI
BSDID   PROC FAR
        MOV     BX,0010         ;move 0010 into BX
        MOV     DI,0005         ;move 0005 into DI
        MOV     CH,[BX][DI]+1   ;move DS:BX+DI+1 into CX
        MOV     CH,[BX+DI+1]    ;same as the above
        MOV     CH,1[BX][DI]    ;same as the above ****** (?)
        RET
BSDID   ENDP
;-----------------------------------------------------------

CDSEG   ENDS
        END MAIN
