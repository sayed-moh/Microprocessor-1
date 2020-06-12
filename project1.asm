include mymacros.inc
                    .MODEL SMALL
;------------------------------------------------------
                    .STACK 64   ;64 BYTES for stack      
;------------------------------------------------------                    
                    .DATA 
                    
                    
                    

playmsg db  "New Game","$"
chat db  "Chat","$"
exitmsg db  "Exit","$"
mode db  ?          ;mode of the main menu to choose new game or chat or exit 
msg6 db  "Enter first player Name( 15 chars )","$"
msg7 db  "Error, Enter Your Name Again please ","$"
msg8 db  "                                   ","$"
name1 db 16,?,15 dup('$')  ;the name of the first player



d1 dw ?     
d11 dw "$"

 
msg9 db  "Enter second player Name( 15 chars )","$"
msg10 db "Error, Enter Your Name Again please  ","$"
msg11 db "                                   ","$"

name2 db 16,?,15 dup('$')  ;the name of the second player

d2 dw ?
d22 dw "$"

yellow db "yellow","$"
green db "green","$"
cyan db "cyan","$"
playermsg db  "Choose Color for player 1","$"
color1 db ?
playermsg2 db  "Choose Color for player 2","$"
color2 db ?
freezemsg db ": Freeze Opponent 10 steps","$"
dizzymsg db ": Dizzies Opponent 10 steps","$"
skullmsg db ": Return Opponent to beginning","$"
medalmsg db ": WIN !","$"
helpmsg db "!! HELP !!","$"                    
                    
                    
player              db ?                ;input to let us know the player that moves 
endgame             db ?                ;bool to let us go to the main menu it activates when we press esc or taking the medal
bool                db ?
X                   DW ?
Y                   DW ? 
color               DB ?                ;input to recive the color in it
direction           db ?                ;input to know the direction of the squares
X1i                 DW 155              ;initial points of player1 
Y1i                 DW 11
X1                  DW 155              ;moving point of player1
Y1                  DW 11

X2                  DW 175              ;initial points of player1 
Y2                  DW 169
X2i                 DW 175              ;moving point of player1
Y2i                 DW 169

checkvar            DB 9                ;check of the moving of right and down directions
msg1                DB  "Press Any Key To Continue...","$"
msg2                DB  "                            ","$"
freezecount1        DB 0
freezecount2        DB 0
ArrayFreeze1        Dw 203,18,208,198  ;coordinates of icon of freeze
ArrayFreeze2        Dw 6,65,11,1       ;coordinates of icon of freeze
ArrayFreeze3        Dw 185,105,190,180 ;coordinates of icon of freeze
ArrayFreeze4        Dw 286,100,291,281 ;coordinates of icon of freeze
ArraySkull1         DW 70,50,75,65     ;coordinates of icon of skull
ArraySkull2         DW 22,166,27,17
ArraySkull3         DW 206,172,211,201
ArraySkull4         DW 219,60,224,214
cursorbool          DB 0
dizzycount1         DB 0
dizzycount2         DB 0
ArrayDizzy1         DW 160,142,165,155 ;coordinates of icon of dizzy
ArrayDizzy2         DW 70,105,75,65
winnermsg           DB "the winner is  ","$"  
player1msg          DB "P1:","$"
player2msg          DB "P2:","$"
;--------------------------------------------------------
                    .CODE                                                 
MAIN                PROC FAR        ;Procdure length (default:NEAR)
                                   MOV AX,@DATA    ;WE Need to mov DS,@DATA
                    MOV DS,AX       ;But we can not do it in a single step
                    
                    Intropage msg1,msg2
                    
                    
                    NameMenu msg6,msg7,msg8,name1

				    NameMenu msg9,msg10,msg11,name2  
				    
				    
				    labelesc:                ;passing initial values 
				    mov X1i ,155
					mov Y1i, 11
					mov X1 , 155
					mov Y1 , 11

					mov X2 , 175
					mov Y2  , 169
					mov X2i  , 175
					mov Y2i  ,  169
					
					mov checkvar  , 9
					
					                    
					mov player ,0      
					mov endgame ,0
					mov bool ,0
					mov X ,0
					mov Y ,0 
					mov color ,0
					mov direction ,0
					
					mov cursorbool ,0
					mov freezecount1, 0
					mov freezecount2  , 0
					mov dizzycount1 , 0
					mov dizzycount2 , 0
				    call MainMenu 
				    
				    cmp mode,1 ;if not a new game mode (chat or exit) jmp to hlt 
				    jnz finalout
				    
				    call colorp1
				    call colorp2
				    call Help 
				    
                    MOV AH,0
                    MOV AL,13h
                    int 10h
                    
                    Call Maze
                    Call Mazev
                    call statusbar
                    Call PLAY
                    
                                       
                    jmp labelesc   
            finalout:
				
				    mov ah,0  ;call video mode
				    mov al,13h
				    int 10h   
                               
                    MOV AH,4Ch
                    int 21h  
                    
                    MAIN ENDP
;--------------------------------------------
MainMenu PROC   ;play is "new game" text ,chat is "chat" text ,exitmsg is the "exit" text,mode is selected mode
										;mode 1 : play , 2:chat , 3:exit  , default is play
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,0  ;call video mode
				mov al,13h
				int 10h
				
				
				mov ah,2 
				mov bh,0
                mov dx,0000h
                int 10h
				
				mov mode,1
				
			

				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				
				lea di,BYTE PTR playmsg
				
				mov cl,8
		loop1z:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,00ch ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop1z
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR chat
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR exitmsg
				int 21h
nokeyz:				
				mov ah,0		;get key pressed
				int 16h
				
				cmp al,0dh     ;if enter 
				jz temp6z
				
				cmp ah,48h     ;if up 
				jz upz
				
				cmp ah,50h     ;if down 
				jz downz
				
				
upz:
				cmp mode,1
				jnz minusz
				mov al,3
				mov mode,al 
				jmp modesz
		minusz: 
				mov al,mode
				dec al
				mov mode,al
				jmp modesz
downz:				
				cmp mode,3
				jnz plusz
				mov al,1
				mov mode,al 
				jmp modesz
		plusz: 
				mov al,mode
				inc al
				mov mode,al
				jmp modesz
				
				
modesz:
			jmp temp5z
		temp4z:
				jmp nokeyz
		temp5z:

			jmp temp7z
			temp6z:
				jmp temp8z
			temp7z:
			
playmodez:
				cmp mode,1
				jnz exitmodez
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				lea di,BYTE PTR playmsg
				
				mov cl,8
		loop2z:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,00ch ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop2z
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR chat
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR exitmsg
				int 21h
				jmp	nokeyz
				
				jmp temp2z
		temp1z:
				jmp temp4z
				temp2z:
				jmp temp9z
		temp8z:
				jmp temp10z
			temp9z:
exitmodez:
				cmp mode,2
				jnz chatmodez
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				lea di,BYTE PTR chat
				
				mov cl,4
		loop3z:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,00ch ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop3z
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR playmsg
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR exitmsg
				int 21h
				
		temp3z:		jmp temp1z
			
				jmp temp1111z
				temp10z:
					jmp end1z
				temp1111z:
chatmodez:					
				cmp mode,3
				jnz temp3z
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				lea di,BYTE PTR exitmsg
				
				mov cl,4
		loop4z:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,00ch ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop4z
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR chat
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR playmsg
				int 21h
				
				
				jmp temp3z
				
				
	end1z:		
				mov ah,0  ;call video mode
				mov al,13h
				int 10h
				
				pop dx
				pop cx
				pop bx
				pop ax
				
                    RET
MainMenu                ENDP  
;-----------------------------------------------------------------
;-------------------------------------------------------------------
;-----------------------------------------------------------------------
help                PROC
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,0  ;call video mode
				mov al,13h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,12
				mov dh,2
				int 10h
				
				lea di,BYTE PTR helpmsg
				
				mov cl,10
		around2:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,00ch ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz around2
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				;------------------------------------
				DrawMedalOld 40,50
				
				mov ah,2			;move curser for print 
				mov dl,6
				mov dh,6
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR medalmsg
				int 21h
				
				;-----------------------------------
				DrawFreezeOld 40,75
				
				mov ah,2			;move curser for print 
				mov dl,6
				mov dh,9
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR freezemsg
				int 21h
				;-----------------------------------
				DrawDizzyOld 40,100
				
				mov ah,2			;move curser for print 
				mov dl,6
				mov dh,12
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR dizzymsg
				int 21h
				;-----------------------------------
				DrawSkullOld 40,123
				
				mov ah,2			;move curser for print 
				mov dl,6
				mov dh,15
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR skullmsg
				int 21h
				;-----------------------------------
				
around1:			

				
				mov ah,2			;move curser for print 
				mov dl,6
				mov dh,20
				int 10h


				mov ah, 9
				lea dx,BYTE PTR msg2
				int 21h
				
				mov cx,03h			;delay
				mov dx,0f000h
				mov ah, 86h
				int 15h
				
				
				mov ah,2			;move curser for print 
				mov dl,6
				mov dh,20
				int 10h


				mov ah, 9
				lea dx,BYTE PTR msg1 ;here
				int 21h
				
				mov cx,08h			;delay
				mov dx,4240h
				mov ah, 86h
				int 15h
				
				mov ah,1
				int 16h
				jz around1
				
				
				;need to clear buffer
				mov ah,0
				int 16h
				
				
				mov ah,0  ;call video mode to clear screen
				mov al,13h
				int 10h
				
				
				pop dx
				pop cx
				pop bx
				pop ax

                    RET
help                ENDP  
;-----------------------------------------------------------------
;-----------------------------------------------------------------------------
;------------------------------------------
colorp2                PROC  ; to get player 2 color
                    push ax
				push bx
				push cx
				push dx
				
				mov ah,0  ;call video mode
				mov al,13h
				int 10h
				
				
				mov ah,2 
				mov bh,0
                mov dx,0000h
                int 10h
				
				mov color2,1
				
			
				mov ah,2			;move curser for print 
				mov dl,10
				mov dh,2
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR playermsg2
				int 21h
				
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				
				lea di,BYTE PTR yellow
				
				mov cl,6
		loop119:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,00Eh ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop119
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR green
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR cyan
				int 21h
nokey19:				
				mov ah,0		;get key pressed
				int 16h
				
				cmp al,0dh     ;if enter 
				jz temp619
				
				cmp ah,48h     ;if up 
				jz up19
				
				cmp ah,50h     ;if down 
				jz down19
				
				
up19:
				cmp color2,1
				jnz minus19
				mov al,3
				mov color2,al 
				jmp modes19
		minus19: 
				mov al,color2
				dec al
				mov color2,al
				jmp modes19
down19:				
				cmp color2,3
				jnz plus19
				mov al,1
				mov color2,al 
				jmp modes19
		plus19: 
				mov al,color2
				inc al
				mov color2,al
				jmp modes19
				
				
modes19:
			jmp temp519
		temp419:
				jmp nokey19
		temp519:

			jmp temp719
			temp619:
				jmp temp819
			temp719:
			
playmode19:
				cmp color2,1
				jnz temp2019
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,10
				mov dh,2
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR playermsg2
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				lea di,BYTE PTR yellow
				
				mov cl,6
		loop219:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,00Eh ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				jmp temp2119
		temp2019:
				jmp exitmode19
				temp2119:
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop219
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR green
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR cyan
				int 21h
				jmp	nokey19
				
		
				jmp temp219
		nottemp119:
				jmp temp419
				temp219:
				jmp temp919
		temp819:
				jmp temp1019
			temp919:
exitmode19:
				cmp color2,2
				jnz chatmode19
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,10
				mov dh,2
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR playermsg2
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				lea di,BYTE PTR green
				
				mov cl,5
		loop319:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,002h ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop319
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR yellow
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR cyan
				int 21h
				
		temp319:		jmp nottemp119
			
				jmp temp1119
				temp1019:
					jmp end119
				temp1119:
chatmode19:					
				cmp color2,3
				jnz temp319
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,10
				mov dh,2
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR playermsg2
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				lea di,BYTE PTR cyan
				
				mov cl,4
		loop419:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,003h ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop419
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR green
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR yellow
				int 21h
				
				
				jmp temp319			
				
	end119:		
				cmp color2,2
				jnz checkcyan19
				mov color2,2
			checkcyan19:
				cmp color2,3
				jnz checkyellow19
				mov color2,3
			checkyellow19:
				cmp color2,1h
				jnz endl219
				mov color2,0eh
			endl219:	
				mov ah,0  ;call video mode
				mov al,13h
				int 10h
				
				pop dx
				pop cx
				pop bx
				pop ax
					
					
                    RET
colorp2               ENDP  
;--------------------------------------------------------------------------------
;--------------------------------------------------------------------------------


colorp1                PROC  ; to get player 1 color
                    push ax
				push bx
				push cx
				push dx
				
				mov ah,0  ;call video mode
				mov al,13h
				int 10h
				
				
				mov ah,2 
				mov bh,0
                mov dx,0000h
                int 10h
				
				mov color1,1
				
			
				mov ah,2			;move curser for print 
				mov dl,10
				mov dh,2
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR playermsg
				int 21h
				
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				
				lea di,BYTE PTR yellow
				
				mov cl,6
		loop11:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,00Eh ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop11
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR green
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR cyan
				int 21h
nokey1:				
				mov ah,0		;get key pressed
				int 16h
				
				cmp al,0dh     ;if enter 
				jz temp61
				
				cmp ah,48h     ;if up 
				jz up1
				
				cmp ah,50h     ;if down 
				jz down1
				
				
up1:
				cmp color1,1
				jnz minus1
				mov al,3
				mov color1,al 
				jmp modes1
		minus1: 
				mov al,color1
				dec al
				mov color1,al
				jmp modes1
down1:				
				cmp color1,3
				jnz plus1
				mov al,1
				mov color1,al 
				jmp modes1
		plus1: 
				mov al,color1
				inc al
				mov color1,al
				jmp modes1
				
				
modes1:
			jmp temp51
		temp41:
				jmp nokey1
		temp51:

			jmp temp71
			temp61:
				jmp temp81
			temp71:
			
playmode1:
				cmp color1,1
				jnz temp201
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,10
				mov dh,2
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR playermsg
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				lea di,BYTE PTR yellow
				
				mov cl,6
		loop21:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,00Eh ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				jmp temp211
		temp201:
				jmp exitmode1
				temp211:
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop21
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR green
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR cyan
				int 21h
				jmp	nokey1
				
		
				jmp temp21
		nottemp11:
				jmp temp41
				temp21:
				jmp temp91
		temp81:
				jmp temp101
			temp91:
exitmode1:
				cmp color1,2
				jnz chatmode1
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,10
				mov dh,2
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR playermsg
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				lea di,BYTE PTR green
				
				mov cl,5
		loop31:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,002h ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop31
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR yellow
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR cyan
				int 21h
				
		temp31:		jmp nottemp11
			
				jmp temp111
				temp101:
					jmp end11
				temp111:
chatmode1:					
				cmp color1,3
				jnz temp31
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,10
				mov dh,2
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR playermsg
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,11
				int 10h
				
				lea di,BYTE PTR cyan
				
				mov cl,4
		loop41:
				
				push ax
				push bx
				push cx
				push dx
				
				mov ah,9 ;Display
				mov bh,0 ;Page 0
				mov al,[di] ;Letter D
				mov cx,1h ;5 times
				mov bl,003h ;Green (A) on white(F) background
				int 10h
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				inc dl
				
				mov ah,2
				int 10h
				inc di
				
				pop dx
				pop cx
				pop bx
				pop ax
				
				sub cl,1
				jnz loop41
				
				mov ah,3h		;get curser pos
				mov bh,0h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,8
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR green
				int 21h
				
				mov ah,2			;move curser for print 
				mov dl,15
				mov dh,5
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR yellow
				int 21h
				
				
				jmp temp31
				
				
	end11:		
				cmp color1,2
				jnz checkcyan1
				mov color1,2
			checkcyan1:
				cmp color1,3
				jnz checkyellow1
				mov color1,3
			checkyellow1:
				cmp color1,1h
				jnz endl21
				mov color1,0eh
			endl21:	
				mov ah,0  ;call video mode
				mov al,13h
				int 10h
				
				pop dx
				pop cx
				pop bx
				pop ax
					
					
                    RET
colorp1                ENDP  


;------------------------------------------------- 
MAZE              PROC    ;drawing the horizontal lines and boundaries
 
MOV CX,0
MOV AL,4
MOV AH,0ch

back1: MOV DX,10      
       int 10h
       
       MOV DX,178
       INT 10h

       INC CX 
       CMP CX,320 

       JNE back1
 
       MOV DX,10
back2: MOV CX,0
       int 10h
       MOV CX,319
       INT 10h
       INC DX
      CMP DX,178
       JNE back2
       
       MOV CX,154
       MOV AL,0

back3: MOV DX,10      ;spaces
       int 10h
       INC CX
       CMP CX,166  
       JNE back3
       
        MOV CX,170
back80: MOV DX,178
        int 10h
        INC CX
        CMP CX,198  
        JNE back80       

MOV AL,4       
MOV DX,22
MOV CX,13
back4: int 10h        ;first H first L
       INC CX
       CMP CX,100
       JNE back4
       
MOV CX,210       
back5: int 10h        ;first H third L
       INC CX
       CMP CX,319
       JNE back5
       
MOV CX,150
back6: int 10h        ;first H second L
       INC CX
       CMP CX,170
       JNE back6
       
MOV DX,34
MOV CX,0
back7: int 10h        ;second H first L
       INC CX
       CMP CX,13
       JNE back7
       
       
MOV CX,198
back8: int 10h        ;second H second L
       INC CX
       CMP CX,307
       JNE back8
       
MOV DX,46
MOV CX,12
back9: int 10h        ;third H first L
       INC CX
       CMP CX,32
       JNE back9        
       
MOV CX,198
back10: int 10h        ;third H second L
       INC CX
       CMP CX,307
       JNE back10
       
MOV DX,58
MOV CX,0
back11: int 10h        ;forth H first L
       INC CX
       CMP CX,13
       JNE back11 
       
MOV CX,130
back12: int 10h        ;forth H second L
       INC CX
       CMP CX,190
       JNE back12
       
MOV CX,250
back13: int 10h         ;forth H third L
        INC CX
        CMP CX,280
        JNE BACK13
        
MOV DX,70        
MOV CX,100                                           
back14: int 10h         ;fifth H first L
        INC CX
        CMP CX,170
        JNE back14
        
MOV CX,183
back15: int 10h         ;fifth H second L
        INC CX
        CMP CX,250
        JNE back15
        
        
        
MOV CX,280
back16: int 10h        
        INC CX          ;fifth H third L
        CMP CX,307
        JNE back16
        
MOV DX,82
MOV CX,13
back17: int 10h        ;sixth H first L
       INC CX
       CMP CX,51
       JNE back17
       
MOV CX,100                                           
back18: int 10h         ;sixth H second L
        INC CX
        CMP CX,130
        JNE back18
        
MOV CX,150
back19: int 10h        ;sixth H third L
       INC CX
       CMP CX,198
       JNE back19                       

MOV CX,210       
back20: int 10h        ;sixth H forth L
       INC CX
       CMP CX,280
       JNE back20
       
MOV CX,307
back21: int 10h        
        INC CX          ;sixth H fifth L
        CMP CX,319
        JNE back21
        
MOV DX,94
MOV CX,0
back22: int 10h        ;seventh H first L
       INC CX
       CMP CX,13
       JNE back22
       
       
MOV CX,51
back23: int 10h        ;seventh H second L
        INC CX
        CMP CX,100
        JNE back23
        
        
MOV CX,170
back24: int 10h        ;seventh H third L
        INC CX
        CMP CX,307
        JNE back24
        
        
MOV DX,106
MOV CX,13
back25: int 10h        ;8 H 1 L
        INC CX
        CMP CX,32
        JNE back25
        
MOV CX,210
back26: int 10h        ;8 H 2 L
        INC CX
        CMP CX,250
        JNE back26
        
MOV CX,280
back27: int 10h        ;8 H 3 L
        INC CX
        CMP CX,307
        JNE back27
        
        
MOV DX,118
MOV CX,0
back28: int 10h        ;9 H 1 L
       INC CX
       CMP CX,13
       JNE back28
       
MOV CX,51
back29: int 10h        ;9 H 2 L       
        INC CX
        CMP CX,150
        JNE back29
        
MOV CX,170
back30: int 10h        ;9 H 3 L
        INC CX
        CMP CX,198
        JNE back30
        
MOV CX,265
back31: int 10h        ;9 H 4 L                              
        INC CX
        CMP CX,280
        JNE back31 
        
MOV DX,130
MOV CX,0
back32: int 10h        ;10 H 1 L
        INC CX        
        CMP CX,100
        JNE back32
        
MOV CX,150
back33: INT 10h        ;10 H 2 L
        INC CX
        CMP CX,170
        JNE back33
        
mov cx,210
back34: int 10h        ;10 H 3 L
        INC CX
        CMP CX,265
        JNE back34
        
MOV CX,280
back35: int 10h        ;10 H 4 L
        INC CX
        CMP CX,307
        JNE back35
        
MOV DX,142
MOV CX,13
back36: int 10h        ;11 H 1 L
        INC CX
        CMP CX,130
        JNE back36
        
MOV CX,170
back37: int 10h        ;11 H 2 L
        INC CX
        CMP CX,210
        JNE back37
        
MOV CX,307
back38: int 10h        ;11 H 3 L
        INC CX
        CMP CX,319
        JNE back38
        
        
MOV DX,154
MOV CX,13
back39: int 10h        ;12 H 1 L
        INC CX
        CMP CX,100
        JNE back39
        
MOV CX,150
back40: int 10h        ;12 H 2 L
        INC CX
        CMP CX,198
        JNE back40
        
MOV CX,210
back41: int 10h        ;12 H 3 L
        INC CX
        CMP CX,307
        JNE back41
        
MOV DX,166
MOV CX,0
back42: int 10h        ;13 H 1 L
        INC CX
        CMP CX,13
        JNE back42
        
MOV CX,51
back43: int 10h        ;13 H 2 L
        INC CX
        CMP CX,150
        JNE back43
        
MOV CX,198
back44: int 10h        ;13 H 3 L
        INC CX
        CMP CX,210
        JNE back44
        
MOV CX,265
back45: int 10h        ;13 H 4 L
        INC CX
        CMP CX,319
        JNE back45
       
        
        mov al,7h     ;the shaded part in the status bar
        mov cx,0
        mov dx,0
        back20001:
        mov dx,0
        int 10h
        inc dx
        int 10h
        inc dx
        int 10h
        inc dx
        int 10h
        inc dx
        int 10h
        inc dx
        int 10h
        inc dx 
        int 10h
        inc dx
        int 10h
        inc dx
        int 10h
        inc dx
        int 10h
        inc cx
        cmp cx,319
        jne back20001
        
        
        mov al,5h
        mov cx,0
        mov dx,0
        back20000:
        int 10h
        add cx,159
        int 10h   
        add cx,160
        int 10h
        sub cx,319
        inc dx
        cmp dx,9
        jbe back20000

ret                         
MAZE ENDP
;----------------------------------------------                             
MAZEV       PROC          ;drawing the vertical lines of the maze
MOV DX,58
MOV CX,13
MOV AL,4
MOV AH,0ch
back46: int 10h        ;1 V 1 L
        INC DX
        CMP DX,70
        JNE back46
        
MOV DX,22
MOV CX,32
back47: int 10h        ;2 V 1 L
        INC DX
        CMP DX,58
        JNE back47
        
MOV DX,70
back48: int 10h       ;2 V 2 L
        INC DX
        CMP DX,130
        JNE back48
        
MOV DX,154
back49: int 10h       ;2 V 3 L
        INC DX
        CMP DX,178
        JNE back49 
        
MOV CX,51
MOV DX,22
back50: int 10h       ;3 V 1 L
        INC DX
        CMP DX,83
        JNE back50
        
MOV DX,94
back51: int 10h       ;3 V 2 L
        INC DX
        CMP DX,118
        JNE back51


MOV CX,100
MOV DX,34
back52: int 10h       ;4 V 1 L
        INC DX
        CMP DX,106
        JNE back52
        
MOV CX,130
MOV DX,10
back53: int 10h        ;5 V 1 L
        INC DX
        CMP DX,58
        JNE back53
        
MOV DX,94
back54: int 10h        ;5 V 2 L
        INC DX
        CMP DX,166
        JNE back54    
    
MOV CX,150
MOV DX,22
back55: int 10h        ;6 V 1 L
        INC DX
        CMP DX,46
        JNE back55
    
MOV DX,82
back56: int 10h        ;6 V 2 L
        INC DX
        CMP DX,119
        JNE back56
        
MOV DX,130
back57: int 10h        ;6 V 3 L
        INC DX
        CMP DX,154
        JNE back57
        
MOV CX,170
MOV DX,22              ;7 V 1 L
back58: int 10h
        INC DX
        CMP DX,58
        JNE back58

MOV DX,94
back59: int 10h        ;7 V 2 L
        INC DX
        CMP DX,106
        JNE back59
        
MOV DX,118
back60: int 10h        ;7 V 3 L
        INC DX
        CMP DX,131
        JNE back60
        
MOV DX,154
back61: int 10h        ;7 V 4 L
        INC DX
        CMP DX,179
        JNE back61
        
MOV CX,198
MOV DX,10
back62: int 10h        ;8 V 1 L
        INC DX
        CMP DX,34
        JNE back62
        
MOV DX,70
back63: int 10h        ;8 V 2 L
        INC DX
        CMP DX,83
        JNE back63
        
MOV DX,94
back64: int 10h        ;8 V 3 L
        INC DX
        CMP DX,119
        JNE back64
        
MOV DX,130
back65: int 10h        ;8 V 4 L
        INC DX
        CMP DX,155
        JNE back65 
        
MOV DX,166
back66: int 10h        ;8 V 5 L
        INC DX
        CMP DX,178
        JNE back66
        
MOV CX,210
MOV DX,46
back67: int 10h        ;9 V 1 L
        INC DX
        CMP DX,70
        JNE back67
        
MOV DX,118
back68: int 10h        ;9 V 2 L
        INC DX
        CMP DX,143
        JNE back68 
        
MOV DX,154
back69: int 10h        ;9 V 3 L
        INC DX
        CMP DX,167
        JNE back69
        
MOV CX,250
MOV DX,106
back70: int 10h        ;10 V 1 L
        INC DX
        CMP DX,130
        JNE back70
        
MOV DX,142
back71: INT 10h        ;10 V 2 L
        INC DX
        CMP DX,154
        JNE back71
        
MOV DX,166
back72: int 10h        ;10 V 3 L
        INC DX
        CMP DX,178
        JNE back72
        
MOV CX,265
MOV DX,58
back73: int 10h        ;11 V 1 L
        INC DX
        CMP DX,82
        JNE back73
        
MOV DX,106
back74: int 10h        ;11 V 2 L
        INC DX
        CMP DX,118
        JNE back74 
        
MOV DX,130
back75: int 10h        ;11 V 3 L
        INC DX
        CMP DX,142
        JNE back75
        
MOV CX,280
MOV DX,82
back76: int 10h        ;12 V 1 L 
        INC DX
        CMP DX,106
        JNE back76
        
MOV DX,118
back77: int 10h        ;12 V 2 L
        INC DX
        CMP DX,154
        JNE back77
        
MOV CX,307
MOV DX,46
back78: int 10h        ;13 V 1 L 
        INC DX
        CMP DX,82
        JNE back78
     
MOV DX,106
back79: int 10h        ;13 V 2 L 
        INC DX
        CMP DX,118
        JNE back79                                               
ret    
MAZEV ENDP 
;------------------------------------------------------
CURSOR PROC                ;drawing the square and moving it
MOV X,CX
MOV Y,DX
CMP cursorbool,1           ;decide if we will draw black square or not
JE cont
CMP direction,1
JE temp2
CMP direction,4            ;to know the direction
JE temp3
CMP direction,2
JE temp4
CMP direction,3
JE temp5
back:                    ;drawing black square
MOV AL,0
push dx
push cx
MOV BX,CX
ADD BX,8                 ; ROW       
MOV AH,0CH             ;DRAW PIXEL COMMAND  
L1:   	INT 10h
add dx,8      
int 10h        
sub dx,8      
inc cx
cmp cx,bx
jnz L1
pop cx
pop dx   
mov bx,dx
add bx,8                       
L2:   	int 10h
add cx,8      
int 10h        
sub cx,8      
inc dx
cmp dx,bx
jle L2 
MOV CX,X
MOV DX,Y
jmp cont
temp2: jmp upcheck         ;temps that jump to the real jump
temp3: jmp leftcheck
temp4: jmp downcheck
temp5: JMP rightcheck
cont: cmp direction,2
JE downcheck2
cmp direction,3
JE rightcheck2
back200: 
MOV X,CX               
MOV Y,DX
MOV AL,COLOR           ;draw the square with its color
push dx
push cx
MOV BX,CX
ADD BX,8                 ; ROW       
MOV AH,0CH             ;DRAW PIXEL COMMAND  
L3:   	INT 10h
add dx,8      
int 10h        
sub dx,8      
inc cx
cmp cx,bx
jnz L3
pop cx
pop dx   
mov bx,dx
add bx,8                       
L4:   	int 10h
add cx,8      
int 10h        
sub cx,8      
inc dx
cmp dx,bx
jle L4 
MOV CX,X
MOV DX,Y
JMP exit1
upcheck: INC DX
jmp back
leftcheck: INC CX
jmp back
downcheck: SUB DX,9         ;the real jumps of the directions
jmp back
rightcheck: SUB CX,9
jmp back
downcheck2: SUB DX,8
jmp back200
rightcheck2: SUB CX,8
jmp back200 
exit1:
ret    
CURSOR ENDP    
;-----------------------------------------------------
PLAY PROC
MOV CX,X1
MOV DX,Y1                          ;new coordinates of player1
push ax
MOV al,color1
MOV color,al                       ;the color of player1
pop ax
CALL CURSOR
MOV CX,X2
MOV DX,Y2                          ;new coordinates of player2
push ax
MOV al,color2
MOV color,al                       ;color of player2
pop ax
CALL CURSOR
DrawSkull 70,50
DrawFreeze 203,18
DrawSkull 22,166
DrawSkull 206,172               ;drawing the power ups of the maze
DrawFreeze 6,65
DrawFreeze 185,105
DrawFreeze 286,100
DrawSkull 219,60
DrawMedal 140,145
DrawDizzy 160,142
DrawDIzzy 70,105
l5:    
CALL CHECK
CMP endgame,1                        
JNE l5       
ret
PLAY ENDP
;-----------------------------------------------------
CHECK PROC
MOV AX,0
mov ah,0
int 16h

CMP AL,27
JE temp

MOV CX,X2
MOV DX,y2

CMP AH,72
JE UP
CMP AH,80                     ;checking the moves of the player 2 by scan codes
JE tempdown
CMP AH,77
JE tempRIGHT
CMP AH,75
JE LEFT

CMP AL,119
JE tempw2
CMP AL,115                   ;checking the moves of player 1by scan codes
JE temps2
CMP AL,100
JE tempD     
CMP AL,97
JE TEMPA2
JMP EXIT
temp: JMP esccheck              ;checking if the user press esc
UP:  MOV CX,X2
     MOV DX,y2
     MOV player,2                 ;jmp for the move up in player2
     CMP dizzycount2,0
     JE dizzycheck
     MOV direction,2               ;checking if the player affected by dizzy power up
     DEC dizzycount2
     ADD DX,9
     JMP cont3
     Dizzycheck:
     MOV direction,1
     DEC DX
     cont3: 
     
     call COLORCHECK
     cmp bool,0
     JE TEMPExit3
     push ax
     MOV al,color2
     MOV color,al
     pop ax
     call cursor
     MOV X2,CX
     MOV Y2,DX
     JMP exit
tempdown: JMP DOWN
tempa2: JMP tempa3
temps2: JMP temps3
tempright: JMP tempright2
tempd : JMP tempd3
tempw2: JMP tempw3     
left: MOV CX,X2
      MOV DX,y2
      MOV player,2
      CMP dizzycount2,0
      JE dizzycheck1                        ;jmp for the move down in player2
      MOV direction,3
      DEC dizzycount2
      ADD CX,9
      JMP cont4
      dizzycheck1:
      MOV direction,4
      DEC CX
      cont4:
      
      call COLORCHECK
      cmp bool,0
      JE tempexit3
      push ax
      MOV al,color2
      MOV color,al
      pop ax
      call cursor
      MOV X2,CX
      MOV Y2,DX
      JMP exit
tempright2: JMP right      
tempw3: JMP tempw
temps3: JMP S
tempa3: JMP tempa
tempexit3: JMP tempexit2
tempd3: JMP tempd2      
down:  MOV CX,X2
      MOV DX,Y2
      MOV player,2
      CMP dizzycount2,0                         ;jmp for the move down in player2
      JE dizzycheck2
      MOV direction,1
      DEC dizzycount2
      DEC DX
      JMP cont5
      Dizzycheck2:
      MOV direction,2
      ADD DX,9
      cont5: 
      
      call COLORCHECK
      cmp bool,0
      JE tempexit
      push ax
      MOV al,color2
      MOV color,al
      pop ax
      call cursor
      MOV X2,CX
      MOV Y2,DX
      JMP tempexit2
      
right:MOV CX,X2
      MOV DX,Y2
      MOV player,2
      CMP dizzycount2,0
      JE dizzycheck3
      MOV direction,4
      DEC dizzycount2
      DEC CX                                ;jmp of the move right in player2
      JMP cont6
      Dizzycheck3:
      MOV direction,3
      ADD CX,9
      cont6: 
      
      call COLORCHECK
      cmp bool,0
      JE tempexit2
      push ax
      MOV al,color2
      MOV color,al
      pop ax
      call cursor
      MOV X2,CX
      MOV Y2,DX
      JMP exit
           
tempA: JMP A
tempexit: JMP EXIT
tempexit2: JMP EXIT
tempw: JMP W
tempd2: JMP D    
S:    MOV CX,X1
      MOV DX,Y1 
      MOV player,1
      CMP dizzycount1,0                    ;jmp for the move down in player1
      JE dizzycheck4
      MOV direction,1
      DEC dizzycount1
      DEC DX
      JMP cont7
      Dizzycheck4:
      MOV direction,2
      ADD DX,9
      cont7: 
      
      call COLORCHECK
      cmp bool,0
      JE tempexit444
      push ax
      MOV al,color1
      MOV color,al
      pop ax
      call cursor
      MOV X1,CX
      MOV Y1,DX
      JMP exit     

A:   MOV CX,X1
      MOV DX,y1                          ;jmp for the move left in player 1
      MOV player,1
      CMP dizzycount1,0
      JE dizzycheck5
      MOV direction,3
      DEC dizzycount1
      ADD CX,9
      JMP cont8
      Dizzycheck5:
      MOV direction,4
      DEC CX
      cont8:
      
      call COLORCHECK
      cmp bool,0
      JE tempexit4
      push ax
      MOV al,color1
      MOV color,al
      pop ax
      call cursor
      MOV X1,CX
      MOV Y1,DX
      JMP exit
tempexit444: JMP tempexit4             
W:    MOV CX,X1                        ;jmp for the move up in player1
     MOV DX,y1
     MOV player,1
     CMP dizzycount1,0
     JE dizzycheck6
     MOV direction,2
     DEC dizzycount1
     ADD DX,9
     JMP cont9
     Dizzycheck6:
     MOV direction,1
     DEC DX
     cont9:
     
     call COLORCHECK
     cmp bool,0
     JE TEMPExit4
     push ax
     MOV al,color1
     MOV color,al
     pop ax
     call cursor
     MOV X1,CX
     MOV Y1,DX
     JMP exit
tempexit4: JMP Exit                  ;jmp of the move right in player1
D:    MOV CX,X1
      MOV DX,Y1
      MOV player,1
      CMP dizzycount1,0
      JE dizzycheck7
      MOV direction,4
      DEC dizzycount1
      DEC CX
      JMP cont10
      Dizzycheck7:
      MOV direction,3
      ADD CX,9
      cont10:
      
      call COLORCHECK
      cmp bool,0
      JE exit
      push ax
      MOV al,color1
      MOV color,al
      pop ax
      call cursor
      MOV X1,CX
      MOV Y1,DX
      JMP exit         
esccheck:
MOV ENDGAME,1
exit:
ret
CHECK ENDP
;------------------------------------------------------
COLORCHECK PROC        ; checking the colours of the icons to know the actions of squares 
    PUSH CX
    PUSH DX
    cmp player,1               ; checking it is player 1 or 2
    JNE check5
    CMP freezecount1,0
    JNE tempfreezed1
    JMP cont2
    check5:                     ;checking that is not freezed
    CMP freezecount2,0
    JNE tempfreezed2
    cont2: MOV checkvar,9
    CMP DIRECtion,1
    JE check2
    CMP DIRECTION,2
    JE check2
    CMP DIRECtion,3                    ;checking directions
    JE check3
    CMP DIRECTION,4
    JE check3
    check2:
    MOV AH,0DH
    MOV BH,0
    INT 10H
    JMP cont33
    tempfreezed1: JMP freezed1
    tempfreezed2: JMP freezed2
    cont33:
    CMP DX,9
    JE label1                     ;preventing players passing the boundaries
    CMP DX,179
    JE label1
    
    cmp al,6h
    jnz cont3333
    call medal                    ;checking if the player clash with the medal
    
    cont3333:                              ;check in all pixels
    cmp al,0             
    je check1
    CMP AL,0Fh
    JNE labeld
    Call Skull                      ;checking if the player clash with the skull
    JMP label1
    labeld:
    CMP AL,1
    JNE labeld2
    CALL Dizzy
    JMP label1                       ;checking if the player clash with the dizzy in the colour1
    labeld2:
    CMP AL,5
    JNE label5
    CALL Dizzy                     ;checking if the player clash with the dizzy in the colour2
    JMP label1                        
    label5:cmp al,11
    JNE label1
    CALL Freeze
    label1: mov bool,0 
    JMP EXIT2
    check1:
    MOV bool,1
    INC CX
    DEC checkvar
    CMP CHECKVAR,0
    JNE check2
    JMP exit2
    
    check3:
    MOV AH,0DH
    MOV BH,0
    INT 10H

    cmp al,0             
    je check4
    CMP AL,0Fh                                         ;checking if the player clash with the skull
    JNE labeldd
    CALL SKULL
    JMP label100
    labeldd:
    CMP AL,1
    JNE labeld3                                     ;checking if the player clash with the dizzy in the colour1
    CALL Dizzy
    JMP label100
    labeld3:
    CMP AL,5
    JNE label6                                                      
    CALL Dizzy                            ;checking if the player clash with the dizzy in the colour2
    JMP label100
    label6:cmp al,11
    JNE label100
    CALL Freeze    
    label100:
    mov bool,0 
    JMP EXIT2
    check4:
    MOV bool,1
    INC DX
    DEC checkvar
    CMP CHECKVAR,0
    JNE check3
    JMP exit2
    freezed1: MOV bool,0        ;dec freeeze count after one move runned out
    DEC freezecount1
    JMP exit2
    freezed2: MOV bool,0
    DEC freezecount2
    exit2:
    POP DX
    POP CX  
ret    
COLORCHECK ENDP
;------------------------------------------------------ 
Freeze PROC                    ;stopping the other player for 10 moves
PUSH CX
PUSH DX
PUSH BX
CMP player,1
JE check6
MOV freezecount1,10 
JMP check7                           ;set the freezed moves to 10
check6:
MOV freezecount2,10
check7:
 
MOV bx,arrayfreeze1[4]
SUB Bx,cx                          ;remove icon of the freeze
MOV ax,arrayfreeze1[6]
ADD Bx,AX
CMP bx,arrayfreeze1[6]
JAE label200
tempexit101: JMP exit101
label200:
CMP  arrayfreeze1[4] ,bx
JNG tempexit101
DrawFreezeBlack arrayfreeze1[0],arrayfreeze1[2]
JMP exit104

exit101:
 
MOV bx,arrayfreeze2[4]
SUB Bx,cx
mov bh,0 
MOV ax,arrayfreeze2[6]
mov ah,0
ADD Bx,AX 
mov bh,0
CMP bx,arrayfreeze2[6]
JAE label201
tempexit102: JMP exit102
label201:
CMP  arrayfreeze2[4] ,bx
JNG tempexit102
DrawFreezeBlack arrayfreeze2[0],arrayfreeze2[2]
JMP exit104
exit102: 
 
MOV bx,arrayfreeze3[4]
SUB Bx,cx 
MOV ax,arrayfreeze3[6]
ADD Bx,AX
CMP bx,arrayfreeze3[6]
JAE label202
tempexit103: JMP exit103
label202:
CMP  arrayfreeze3[4] ,bx
JNG tempexit103
DrawFreezeBlack arrayfreeze3[0],arrayfreeze3[2]
jmp exit104
exit103:
 
MOV bx,arrayfreeze4[4]
SUB Bx,cx 
MOV ax,arrayfreeze4[6]
ADD Bx,AX
CMP bx,arrayfreeze4[6]
JAE label203
tempexit104: JMP exit104
label203:
CMP  arrayfreeze4[4] ,bx
JNG tempexit104
DrawFreezeBlack arrayfreeze4[0],arrayfreeze4[2]
                    exit104:
 
 
POP BX
POP DX
POP CX    
ret
freeze ENDP
;-------------------------------------------------------------------------------
Skull PROC                ;returning the other player into the initial position
PUSH CX
PUSH DX
PUSH AX    
CMP player,1
JE check66
MOV CX,X1
MOV DX,Y1
MOV COLOR,0
mov direction,1
mov cursorbool,1              ;to draw black square in the old place
CALL CURSOR
MOV CX,X1i  
MOV DX,y1i
MOV al,color1
MOV COLOR,Al
mov direction,1
mov cursorbool,0
CALL CURSOR
MOV ax,x1i
MOV x1,Ax                  ;returning player 1 to its initial condition 
MOV ax,y1i
MOV y1,Ax 
JMP check77
check66:
MOV CX,X2
MOV DX,Y2
MOV COLOR,0
mov direction,1
mov cursorbool,1 
CALL CURSOR
MOV CX,X2i                        ;returning player 2 to its initial condition
MOV DX,Y2i
MOV al,color2
MOV COLOR,Al
mov direction,1
mov cursorbool,0
CALL CURSOR
MOV ax,x2i
MOV x2,Ax
MOV ax,y2i
MOV y2,Ax
check77: 

POP AX
pop dx
pop cx
push ax
push cx
push dx
MOV bx,arraySkull1[4]
SUB Bx,cx
mov bh,0 
MOV ax,arrayskull1[6]                       ;rmoving the skull icon when any of the two players clash with it
mov ah,0
ADD Bx,AX
mov bh,0
CMP bx,arrayskull1[6]
JAE label300
tempexit201: JMP exit201
label300:
CMP  arrayskull1[4] ,bx
JNG tempexit201
DrawskullBlack arrayskull1[0],arrayskull1[2]
JMP exit204

exit201:
 
MOV bx,arrayskull2[4]
SUB Bx,cx
mov bh,0
MOV ax,arrayskull2[6]
mov ah,0
ADD Bx,AX
mov bh,0 
CMP bx,arrayskull2[6]
JAE label301
tempexit202: JMP exit202
label301:
CMP  arrayskull2[4] ,bx
JNG tempexit202
DrawskullBlack arrayskull2[0],arrayskull2[2]
JMP exit204
exit202: 
 
MOV bx,arrayskull3[4]
SUB Bx,cx 
MOV ax,arrayskull3[6]
ADD Bx,AX
CMP bx,arrayskull3[6]
JAE label302
tempexit203: JMP exit203
label302:
CMP  arrayskull3[4] ,bx
JNG tempexit203
DrawskullBlack arrayskull3[0],arrayskull3[2]
jmp exit204
exit203:
 
MOV bx,arrayskull4[4]
SUB Bx,cx 
MOV ax,arrayskull4[6]
ADD Bx,AX
CMP bx,arrayskull4[6]
JAE label303
tempexit204: JMP exit204
label303:
CMP  arrayskull4[4] ,bx
JNG tempexit204
DrawskullBlack arrayskull4[0],arrayskull4[2]
exit204: 
                    
pop dx                    
pop cx
pop ax                   
mov cursorbool,0                       
ret
Skull ENDP    
;-----------------------------------------------------------------
Dizzy PROC                      ;reverse the directions to the another player 
PUSH CX
PUSH DX
PUSH BX    
CMP player,1
JE check666
MOV dizzycount1,10            ;setting the count by 10 moves
JMP check777
check666:
MOV dizzycount2,10
check777:

MOV bx,arrayDizzy1[4]
SUB Bx,cx
mov bh,0 
MOV ax,arrayDizzy1[6]               ;drawing the black dizzy by the true coordinates 
mov ah,0
ADD Bx,AX
mov bh,0
CMP bx,arrayDizzy1[6]
JAE label400
tempexit301: JMP exit301
label400:
CMP  arrayDizzy1[4] ,bx
JNG tempexit301
DrawDizzyBlack arrayDizzy1[0],arrayDizzy1[2]
JMP exit302

exit301:
 
MOV bx,arrayDizzy2[4]
SUB Bx,cx
mov bh,0
MOV ax,arrayDizzy2[6]
mov ah,0
ADD Bx,AX
mov bh,0 
CMP bx,arrayDizzy2[6]
JAE label401
tempexit302: JMP exit302
label401:
CMP  arrayDizzy2[4] ,bx
JNG tempexit302
DrawDizzyBlack arrayDizzy2[0],arrayDizzy2[2]
JMP exit302
exit302:
POP BX
POP DX
POP CX
ret
Dizzy ENDP              
;---------------------------------------
 medal proc             ; getting the winner by clashing the medal in the maze
    push cx
    push bx
    push dx 
    
                         MOV AH,0
                         MOV AL,13h
                         int 10h
                         
                         
                        mov ah,2 
                        mov dx,0A0Ah 
                        int 10h 
                        
                        
                         mov ah, 9  
                         mov dx, offset winnermsg 
                         int 21h   
                         
                         cmp player,1 
                         jnz labelp2
                         
                         mov ah, 9  
                         mov dx, offset name1[2]
                         int 21h 
                         jmp exitt
                         
                         labelp2:
 
                          mov ah, 9  
                          mov dx, offset name2[2]
                          int 21h 
                          jmp exitt
 
    exitt:   
    
mov ah,0
 int 16h 
    mov endgame,1           ;getting to the main menu 
    POP BX
    POP DX
    POP CX
    ret
    
    
    medal endp
;------------------------------------------------
statusbar proc      ;creating the statues bar
            push cx
              push bx
              push dx
            
             mov ah,2 
             mov dx,0001h 
             int 10h
                                                                             

                     
            lea si , player1msg                           ;printing  p by the color of the player 1                        
            mov ah,09h
            mov bh,0
            mov al,[si]
            mov bl,00h
            mov cx,1h 
            mov bl,color1 ;Green (A) on white(F) background 
            int 10h
            
            
            mov ah,2 
            mov dx,0002h
             int 10h               
            
            inc si
             mov ah,09h
            mov bh,0                                           ;printing  1 by the color of the player 1  
            mov al,[si]
            mov bl,00h
            mov cx,1h 
            mov bl,color1 ;Green (A) on white(F) background 
            int 10h
     
             mov ah,2 
            mov dx,0003h
            int 10h
             
              inc si
             mov ah,09h
            mov bh,0
            mov al,[si]
            mov bl,00h                                            ;printing  : by the color of the player 1  
            mov cx,1h 
            mov bl,color1 ;Green (A) on white(F) background 
            int 10h
     
              mov ah,2 
            mov dx,0004h
            int 10h
            
            mov ah, 9         
            mov dx, offset name1[2]
            int 21h
     
     
      mov ah,2 
     mov dx,0015h 
     int 10h
     
     
              lea di , player2msg   
            mov ah,09h
            mov bh,0                                                    ;printing  p by the color of the player 2
            mov al,[di]
            mov bl,00h
            mov cx,1h 
            mov bl,color2 ;Green (A) on white(F) background 
            int 10h
            
            
mov ah,2 
mov dx,0016h
 int 10h               
            
            inc di
             mov ah,09h
            mov bh,0
            mov al,[di]
            mov bl,00h                                                   ;printing  2 by the color of the player 2  
            mov cx,1h 
            mov bl,color2 ;Green (A) on white(F) background 
            int 10h
     
             mov ah,2 
            mov dx,0017h
            int 10h
             
              inc di
             mov ah,09h
            mov bh,0                                                          ;printing  : by the color of the player 2
            mov al,[di]
            mov bl,00h
            mov cx,1h 
            mov bl,color2 ;Green (A) on white(F) background 
            int 10h
     
              mov ah,2 
            mov dx,0018h
            int 10h
            
            mov ah, 9         
            mov dx, offset name2[2]
            int 21h
                  
           mov cursorbool,0        
                
                
     POP BX
    POP DX
    POP CX
    ret
    statusbar endp 
    
    










END MAIN                                                     