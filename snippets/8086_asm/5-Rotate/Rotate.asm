TITLE   ROTATIONS - ROR, ROL, RCR, RCL
PAGE    60,132
;---------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;---------------------------------
DTSEG   SEGMENT
DTSEG   ENDS
;---------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV AX,DTSEG
        MOV DS,AX
        AND AX,00H      ;clear AX

        ;ROR
        MOV AL,36H      ;AL=0011 0110
        MOV CL,3H       ;number of times to ROR
        ROR AL,CL       ;AL=1100 0110?

        ;ROL
        MOV AL,36H      ;AL=0011 0110
        MOV CL,5H       ;number of times to ROL
        ROL AL,CL       ;AL=1100 1100 (WRONG)
                        ;AL=1100 0110

        ;RCR
        CLC             ;clear CF because rotating through CF
        MOV AL,36H      ;AL=0011 0110 [0]
        MOV CL,5H       ;number of times to RCR
        RCR AL,CL       ;AL=0110 0001 [1]

        ;RCL
        CLC             ;clear CF because rotating through CF
        MOV AL,36H      ;AL=0011 0110 [0]
        MOV CL,5H       ;number of times to RCL
        RCL AL,CL       ;AL=1100 0011 [0]

        MOV AH,4CH      ;EXIT
        INT 21H         ;interrupt
MAIN    ENDP
CDSEG   ENDS
        END MAIN
