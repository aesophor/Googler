TITLE   SUBTRACT WITH BORROW
PAGE    60,132
;---------------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;---------------------------------------------
DTSEG   SEGMENT
DATA1   DD 62562FAH
        ORG 8
DATA2   DD 412963BH
        ORG 16
RESULT  DD ?
DTSEG   ENDS
;---------------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV  AX,DTSEG
        MOV  DS,AX
        CLC                      ;clear Carry Flag
        MOV  CX,02               ;load loop counter
        LEA  SI,DATA1            ;load pointer to DATA1
SUBW:   MOV  AX,WORD PTR [SI]    ;load 2 bytes
        ;SUB  AX,WORD PTR 8[SI]   ;subtract from DATA1
        ;----check for previous round----
        MOV  DX,WORD PTR [SI]-2
        SUB  DX,WORD PTR 8[SI]-2
        SBB  AX,WORD PTR 8[SI]
        MOV  16[SI],AX           ;store in RESULT
        ADD  SI,2                ;point to next word
        LOOP SUBW                ;continue until finished
        SBB  AX,00
        MOV  16[SI-2],AX
        INT  21H                 ;interrupt
        MOV  AH,4CH              ;EXIT
        INT  21H                 ;interrupt
MAIN    ENDP
CDSEG   ENDS
        END  MAIN
