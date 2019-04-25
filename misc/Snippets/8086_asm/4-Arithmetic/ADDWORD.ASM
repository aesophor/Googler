TITLE   ADDING 5 WORDS
PAGE    60,132
;----------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;----------------------------------------
DTSEG   SEGMENT
DATA    DW 27345,28521,29533,30105,32375
        ORG 16
SUM     DW 2 DUP(?)
DTSEG   ENDS
;----------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV AX,DTSEG
        MOV DS,AX
        MOV SI,OFFSET DATA      ;load pointer to DATA
        MOV DI,OFFSET SUM       ;load pointer to SUM
        MOV CX,5                ;load loop counter
        MOV AX,00               ;AX will hold the sum
        MOV BX,00               ;BX will hold the carry
ADDW:   ADD AX,WORD PTR [SI]    ;add data to AX
        ADC BX,00               ;store carry in BX
        ADD SI,2                ;point to next word
        DEC CX                  ;decrement loop counter
        JNZ ADDW                ;continue if not finished
        MOV [DI],AX             ;store the result
        MOV [DI+2],BX           ;also store the carry
;<NOTE>: "MOV SUM,AX" and "MOV SUM+2,AX" is also fine.
        MOV AH,4CH              ;EXIT
        INT 21H
MAIN    ENDP
CDSEG   ENDS
        END MAIN
