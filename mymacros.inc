;-----------------MACROS------

NameMenu MACRO msg,errormsg,clearmsg,name
				LOCAL check
				LOCAL back
				LOCAL endl
				LOCAL loop1
				push ax
				push bx
				push cx
				push dx
				
				
				mov ah,0  ;call video mode
				mov al,13h
				int 10h
				
				mov ah,2			;move curser for print 
				mov dl,2
				mov dh,5
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR msg
				int 21h
back:			
				mov ah,2			;move curser for read 
				mov dl,5
				mov dh,8
				int 10h
				
				push cx
				mov cx,16
				lea si,name
				add si,2
		loop1:
				mov [si],BYTE PTR "$"
				inc si
				sub cx,1
				jnz loop1
				pop cx
				
				mov ah,0AH
                mov dx,offset name
                int 21h  
				
				cmp name[2],41h
				jl check
				cmp name[2],7ah
				jg check
				
				
				mov ah,0  ;call video mode
				mov al,13h
				int 10h
				
				jmp endl
		check:
				mov ah,2			;move curser for print 
				mov dl,2
				mov dh,5
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR errormsg
				int 21h
				
				mov ah,2			;move curser for read 
				mov dl,5
				mov dh,8
				int 10h
				
				mov ah, 9
				lea dx,BYTE PTR clearmsg
				int 21h 
				
				jmp back
				
endl:				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM NameMenu 





DrawVirticalLine MACRO x,y1,y2,Color ;y1 is the beginning from up ,y2 is the enddown , C is the color y1<y2
				LOCAL BACK1
				push ax
				push bx
				push cx
				push dx
				
				mov bx,WORD PTR y2
				sub bx,WORD PTR y1
				
				mov cx, x ;Column
				mov dx,WORD PTR y1 ;Row
				mov al,BYTE PTR Color ;Pixel color
				mov ah,0ch ;Draw Pixel Command

BACK1:			
				
				
				int 10h
				inc dx
				
				sub bx,1
				jnz BACK1
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawVirticalLine 

DrawVirticalLineallreg MACRO x,y1,y2,Color ;y1 is the beginning from up ,y2 is the enddown , C is the color y1<y2
				LOCAL BACK1
				push ax
				push bx
				push cx
				push dx
				
				mov bx, y2
				sub bx, y1
				
				mov cx, x ;Column
				mov dx,y1 ;Row
				mov al,BYTE PTR Color ;Pixel color
				mov ah,0ch ;Draw Pixel Command

BACK1:			
				
				
				int 10h
				inc dx
				
				sub bx,1
				jnz BACK1
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawVirticalLineallreg


 
DrawDizzyOld MACRO x,y
				push ax
				push bx
				push cx
				push dx
				
				mov al,1 ;Pixel color
				mov ah,0ch ;Draw Pixel Command
				
				
				;starting from center color blue
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				int 10h 				
				sub dx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				sub cx,1
				int 10h			
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub cx,1
				int 10h			
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h			
				sub cx,1
				int 10h			
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub cx,1
				int 10h			
				sub cx,1
				int 10h			
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h	
				
				mov al,5 ;Pixel color
				;starting from right the center color magenta
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1
				int 10h
				add dx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawDizzyOld

 
  DrawDizzy MACRO x,y
				push ax
				push bx
				push cx
				push dx
				
				mov al,1 ;Pixel color
				mov ah,0ch ;Draw Pixel Command
				
				
				;starting from center color blue
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				int 10h 				
				sub dx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				sub cx,1
				int 10h			
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub cx,1
				int 10h			
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h			
				sub cx,1
				int 10h			
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub cx,1
				int 10h			
				sub cx,1
				int 10h			
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h	
				
				mov al,5 ;Pixel color
				;starting from right the center color green
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1
				int 10h
				add dx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawDizzy


 
 
 				
 
DrawDizzyBlack MACRO x,y
				push ax
				push bx
				push cx
				push dx
				
				mov al,0 ;Pixel color
				mov ah,0ch ;Draw Pixel Command
				
				
				;starting from center color black
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				int 10h 				
				sub dx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				sub cx,1
				int 10h			
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub cx,1
				int 10h			
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add cx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h				
				add dx,1
				int 10h			
				sub cx,1
				int 10h			
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub cx,1
				int 10h			
				sub cx,1
				int 10h			
				sub cx,1
				int 10h				
				sub cx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h				
				sub dx,1
				int 10h	
				
				mov al,0 ;Pixel color
				;starting from right the center color black
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1
				int 10h
				add dx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				add dx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub cx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				sub dx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				add cx,1
				int 10h
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawDizzyBlack				
				
				
DrawFreezeOld MACRO x,y
				push ax
				push bx
				push cx
				push dx
				
				mov al,11 ;Pixel color
				mov ah,0ch ;Draw Pixel Command
				
				
				;the center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				int 10h 
				
				add cx,1
				int 10h 
				
				sub cx,2
				int 10h 
				
				add cx,1
				add dx,1
				int 10h 
				
				sub dx,2
				int 10h 
				
				;the upper left quarter
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1
				sub dx,1
				
				int 10h 
				
				sub dx,1
				int 10h 
				
				sub dx,1
				int 10h 
				
				sub cx,1
				sub dx,1
				int 10h 
				
				add dx,3
				int 10h 
				
				sub cx,1
				sub dx,1
				int 10h 
				
				sub cx,1
				int 10h 
				
				 
				
				;the upper center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub dx,4
				int 10h 
				
				;the lower center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add dx,4
				int 10h 
				
				;the upper right
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub dx,1
				add cx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				add cx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub dx,1
				add cx,2
				int 10h
				
				sub dx,1
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				;the right center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,3
				int 10h
				
				add cx,1
				int 10h
				
				;the left center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,3
				int 10h
				
				sub cx,1
				int 10h
				
				
				;the lower right
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,2
				add dx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				add cx,1
				int 10h
				
				
				;the lower left
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,2
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				sub cx,1
				int 10h
				
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawFreezeOld

   
 DrawFreeze MACRO x,y
				push ax
				push bx
				push cx
				push dx
				
				mov al,11 ;Pixel color
				mov ah,0ch ;Draw Pixel Command
				
				
				;the center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				int 10h 
				
				add cx,1
				int 10h 
				
				sub cx,2
				int 10h 
				
				add cx,1
				add dx,1
				int 10h 
				
				sub dx,2
				int 10h 
				
				;the upper left quarter
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1
				sub dx,1
				
				int 10h 
				
				sub dx,1
				int 10h 
				
				sub dx,1
				int 10h 
				
				sub cx,1
				sub dx,1
				int 10h 
				
				add dx,3
				int 10h 
				
				sub cx,1
				sub dx,1
				int 10h 
				
				sub cx,1
				int 10h 
				
				 
				
				;the upper center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub dx,4
				int 10h 
				
				;the lower center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add dx,4
				int 10h 
				
				;the upper right
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub dx,1
				add cx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				add cx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub dx,1
				add cx,2
				int 10h
				
				sub dx,1
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				;the right center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,3
				int 10h
				
				add cx,1
				int 10h
				
				;the left center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,3
				int 10h
				
				sub cx,1
				int 10h
				
				
				;the lower right
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,2
				add dx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				add cx,1
				int 10h
				
				
				;the lower left
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,2
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				sub cx,1
				int 10h
				
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawFreeze  

   
   
DrawFreezeBlack MACRO x,y
				push ax
				push bx
				push cx
				push dx
				
				mov al,0 ;Pixel color
				mov ah,0ch ;Draw Pixel Command
				
				
				;the center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				int 10h 
				
				add cx,1
				int 10h 
				
				sub cx,2
				int 10h 
				
				add cx,1
				add dx,1
				int 10h 
				
				sub dx,2
				int 10h 
				
				;the upper left quarter
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1
				sub dx,1
				
				int 10h 
				
				sub dx,1
				int 10h 
				
				sub dx,1
				int 10h 
				
				sub cx,1
				sub dx,1
				int 10h 
				
				add dx,3
				int 10h 
				
				sub cx,1
				sub dx,1
				int 10h 
				
				sub cx,1
				int 10h 
				
				 
				
				;the upper center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub dx,4
				int 10h 
				
				;the lower center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add dx,4
				int 10h 
				
				;the upper right
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub dx,1
				add cx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				add cx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub dx,1
				add cx,2
				int 10h
				
				sub dx,1
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				;the right center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,3
				int 10h
				
				add cx,1
				int 10h
				
				;the left center
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,3
				int 10h
				
				sub cx,1
				int 10h
				
				
				;the lower right
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,2
				add dx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				add cx,1
				int 10h
				
				
				;the lower left
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,2
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				sub cx,1
				int 10h
				
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawFreezeBlack


DrawSkullOld MACRO x,y
				push ax
				push bx
				push cx
				push dx
				
				mov al,15 ;Pixel color
				mov ah,0ch ;Draw Pixel Command
				
				
				;the right eye & right tooth
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1
				sub dx,1
				int 10h
				
				add cx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1 
				int 10h 
				
				add cx,1 
				int 10h 
				
				sub cx,1
				sub dx,1 
				;int 10h 
				
				add dx,3
				int 10h 
				add dx,1
				int 10h 
				
				
				;the left eye & left tooth
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1
				sub dx,1
				int 10h
				sub cx,1
				int 10h
				
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1 
				int 10h 
				
				sub cx,1 
				int 10h 
				
				add cx,1
				sub dx,1 
				;int 10h 
				
				add dx,3
				int 10h 
				add dx,1
				int 10h 
				
				;start on paper 
				
				add dx,1 ;start
				int 10h 
				
				sub cx,1
				int 10h 
				
				sub cx,1
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub cx,1
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				add cx,1
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				sub cx,1
				int 10h
				
				sub cx,1
				int 10h
				
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawSkullOld
DrawSkull MACRO x,y
				push ax
				push bx
				push cx
				push dx
				
				mov al,15 ;Pixel color
				mov ah,0ch ;Draw Pixel Command
				
				
				;the right eye & right tooth
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1
				sub dx,1
				int 10h
				
				add cx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1 
				int 10h 
				
				add cx,1 
				int 10h 
				
				sub cx,1
				sub dx,1 
				;int 10h 
				
				add dx,3
				int 10h 
				add dx,1
				int 10h 
				
				
				;the left eye & left tooth
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1
				sub dx,1
				int 10h
				sub cx,1
				int 10h
				
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1 
				int 10h 
				
				sub cx,1 
				int 10h 
				
				add cx,1
				sub dx,1 
				;int 10h 
				
				add dx,3
				int 10h 
				add dx,1
				int 10h 
				
				;start on paper 
				
				add dx,1 ;start
				int 10h 
				
				sub cx,1
				int 10h 
				
				sub cx,1
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub cx,1
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				add cx,1
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				sub cx,1
				int 10h
				
				sub cx,1
				int 10h
				
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawSkull

    

DrawSkullBlack MACRO x,y
				push ax
				push bx
				push cx
				push dx
				
				mov al,0 ;Pixel color
				mov ah,0ch ;Draw Pixel Command
				
				
				;the right eye & right tooth
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1
				sub dx,1
				int 10h
				
				add cx,1
				int 10h
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				add cx,1 
				int 10h 
				
				add cx,1 
				int 10h 
				
				sub cx,1
				sub dx,1 
				;int 10h 
				
				add dx,3
				int 10h 
				add dx,1
				int 10h 
				
				
				;the left eye & left tooth
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1
				sub dx,1
				int 10h
				sub cx,1
				int 10h
				
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,1 
				int 10h 
				
				sub cx,1 
				int 10h 
				
				add cx,1
				sub dx,1 
				;int 10h 
				
				add dx,3
				int 10h 
				add dx,1
				int 10h 
				
				;start on paper 
				
				add dx,1 ;start
				int 10h 
				
				sub cx,1
				int 10h 
				
				sub cx,1
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub cx,1
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				add cx,1
				sub dx,1
				int 10h
				
				sub dx,1
				int 10h
				
				sub dx,1
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				add cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				add dx,1
				int 10h
				
				sub cx,1
				add dx,1
				int 10h
				
				sub cx,1
				int 10h
				
				sub cx,1
				int 10h
				
				
				pop dx
				pop cx
				pop bx
				pop ax
ENDM DrawSkullBlack



DrawMedalOld MACRO x,y
				LOCAL loop1
				LOCAL loop2
				LOCAL loop3
				LOCAL loop4
				
				push ax
				push bx
				push cx
				push dx
				mov ah,0ch ;Draw Pixel Command
				;corners
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				mov al,6 ;Pixel color
				
				sub cx,3
				sub dx,3
				int 10h
				
				add dx,6
				int 10h
				
				add cx,6
				int 10h
				
				sub dx,6
				int 10h
				
				;upper 
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,2
				sub dx,4
				
				mov bl,5
loop1:			
				int 10h	
				add cx,1
				
				sub bl,1
				jnz loop1
				
				; lower
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,2
				add dx,4
				
				mov bl,5
loop2:			
				int 10h
				add cx,1
				
				sub bl,1
				jnz loop2
				
				; lefter
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,4  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,6
				
				
				;righter
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,4  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,6
				
				;fill 1
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,3  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 7
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,3  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 2
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,2  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 6
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,2  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 3
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,1  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 5
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,1  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 4
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				
				;shadow
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				mov ah,0ch ;Draw Pixel Command
				mov al,0fh ;Pixel color
				sub cx,2
				add dx,2
				int 10h
				add cx,1
				int 10h
				sub cx,1
				sub dx,1
				int 10h
				
				pop dx
				pop cx
				pop bx
				pop ax
				
ENDM DrawMedalOld


 DrawMedal MACRO x,y
				LOCAL loop1
				LOCAL loop2
				LOCAL loop3
				LOCAL loop4
				
				push ax
				push bx
				push cx
				push dx
				mov ah,0ch ;Draw Pixel Command
				;corners
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				mov al,6 ;Pixel color
				
				sub cx,3
				sub dx,3
				int 10h
				
				add dx,6
				int 10h
				
				add cx,6
				int 10h
				
				sub dx,6
				int 10h
				
				;upper 
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,2
				sub dx,4
				
				mov bl,5
loop1:			
				int 10h	
				add cx,1
				
				sub bl,1
				jnz loop1
				
				; lower
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,2
				add dx,4
				
				mov bl,5
loop2:			
				int 10h
				add cx,1
				
				sub bl,1
				jnz loop2
				
				; lefter
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,4  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,6
				
				
				;righter
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,4  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,6
				
				;fill 1
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,3  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 7
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,3  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 2
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,2  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 6
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,2  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 3
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,1  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 5
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,1  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				;fill 4
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0eh
				
				
				;shadow
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				mov ah,0ch ;Draw Pixel Command
				mov al,0fh ;Pixel color
				sub cx,2
				add dx,2
				int 10h
				add cx,1
				int 10h
				sub cx,1
				sub dx,1
				int 10h
				
				pop dx
				pop cx
				pop bx
				pop ax
				
ENDM DrawMedal


 
DrawMedalBlack MACRO x,y
				LOCAL loop1
				LOCAL loop2
				LOCAL loop3
				LOCAL loop4
				
				push ax
				push bx
				push cx
				push dx
				mov ah,0ch ;Draw Pixel Command
				;corners
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				mov al,0 ;Pixel color
				
				sub cx,3
				sub dx,3
				int 10h
				
				add dx,6
				int 10h
				
				add cx,6
				int 10h
				
				sub dx,6
				int 10h
				
				;upper 
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y ;Row
				
				sub cx,2
				sub dx,4
				
				mov bl,5
loop1:			
				int 10h	
				add cx,1
				
				sub bl,1
				jnz loop1
				
				; lower
				
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,2
				add dx,4
				
				mov bl,5
loop2:			
				int 10h
				add cx,1
				
				sub bl,1
				jnz loop2
				
				; lefter
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,4  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,0
				
				
				;righter
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,4  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,0
				
				;fill 1
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,3  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,0
				
				;fill 7
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,3  ;x coord
				sub dx,2  ;y1
				mov bx,dx	;y2
				add bx,5	
				DrawVirticalLineallreg cx,dx,bx,0
				
				;fill 2
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,2  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0
				
				;fill 6
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,2  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0
				
				;fill 3
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub cx,1  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0
				
				;fill 5
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				add cx,1  ;x coord
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0
				
				;fill 4
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				
				sub dx,3  ;y1
				mov bx,dx	;y2
				add bx,7	
				DrawVirticalLineallreg cx,dx,bx,0
				
				
				;shadow
				mov cx,WORD PTR x ;Column
				mov dx,WORD PTR y;Row
				mov ah,0ch ;Draw Pixel Command
				mov al,0 ;Pixel color
				sub cx,2
				add dx,2
				int 10h
				add cx,1
				int 10h
				sub cx,1
				sub dx,1
				int 10h
				
				pop dx
				pop cx
				pop bx
				pop ax
				
ENDM DrawMedalBlack




IntroPage MACRO	msg,msg2              
               LOCAL loop1
			   LOCAL loop2
               LOCAL loop3
			   LOCAL loop4
			   LOCAL loop5
               LOCAL loop6
			   LOCAL loop7
			   LOCAL loop8
               LOCAL loop9
			   LOCAL loop10
			   LOCAL loop11
			   LOCAL loop12
               LOCAL loop13
			   LOCAL loop14
			   LOCAL loop15
               LOCAL loop16
			   LOCAL loop17
			   LOCAL loop18
               LOCAL loop19
			   LOCAL loop20
			   LOCAL loop21
			   LOCAL loop22
               LOCAL loop23
			   LOCAL loop24
			   LOCAL loop25
               LOCAL loop26
			   LOCAL loop27
			   LOCAL loop28
               LOCAL loop29
			   LOCAL loop30
			   LOCAL loop31
			   LOCAL loop32
               LOCAL loop33
			   LOCAL loop34
			   LOCAL loop35
               LOCAL loop36
			   LOCAL loop37
			   LOCAL loop38
               LOCAL loop39
			   LOCAL loop40
			   LOCAL loop41
			   LOCAL loop42
               LOCAL loop43
			   LOCAL loop44
			   LOCAL loop45
               LOCAL loop46
			   LOCAL loop47
			   LOCAL loop48
               LOCAL loop49
			   LOCAL loop50
			   LOCAL loop51
			   LOCAL loop52
               LOCAL loop53
			   LOCAL loop54
			   LOCAL loop55
               LOCAL loop56
			   LOCAL loop57
			   LOCAL loop58
               LOCAL loop59
			   LOCAL loop60
			   LOCAL loop61
			   LOCAL loop62
               LOCAL loop63
			   LOCAL loop64
			   LOCAL loop65
               LOCAL loop66
			   LOCAL loop67
			   LOCAL loop68
               LOCAL loop69
			   LOCAL loop70
			   LOCAL loop71
			   LOCAL loop72
               LOCAL loop73
			   LOCAL loop74
			   LOCAL loop75
               LOCAL loop76
			   LOCAL loop77
			   LOCAL loop78
               LOCAL loop79
			   LOCAL loop80
			   LOCAL loop81
			   LOCAL loop82
               LOCAL loop83
			   LOCAL loop84
			   LOCAL loop85
               LOCAL loop86
			   LOCAL loop87
			   LOCAL loop88
               LOCAL loop89
			   LOCAL loop90
			   LOCAL loop91
			   
			   
			   
				mov ah,0  ;call video mode
				mov al,13h
				int 10h
				
				
				mov bl,5
				mov cx,90
loop1:
				DrawVirticalLine cx,80,130,0fh
				inc cx

				sub bl,1
				jnz loop1
				
				mov cx,00h				
				mov dx,0f000h
				mov ah, 86h
				int 15h
				
				
				mov bl,5
				mov cx,95
loop2:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop2	

				
				mov bl,5
				mov cx,95
loop3:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop3	

				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h
				
				mov bl,5
				mov cx,100
loop4:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop4


				
				mov bl,5
				mov cx,100
loop5:
				DrawVirticalLine cx,90,130,0fh
				inc cx

				sub bl,1
				jnz loop5		



				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h
				
				
				mov bl,5
				mov cx,105
loop6:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop6


				
				mov bl,5
				mov cx,105
loop7:
				DrawVirticalLine cx,90,95,0fh
				inc cx

				sub bl,1
				jnz loop7	
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h
				
				mov bl,5
				mov cx,110
loop8:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop8


				
				mov bl,5
				mov cx,110
loop9:
				DrawVirticalLine cx,90,115,0fh
				inc cx

				sub bl,1
				jnz loop9
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h			
				
				mov bl,5
				mov cx,115
loop10:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop10


				
				mov bl,5
				mov cx,115
loop11:
				DrawVirticalLine cx,90,95,0fh
				inc cx

				sub bl,1
				jnz loop11
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,120
loop12:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop12


				
				mov bl,5
				mov cx,120
loop13:
				DrawVirticalLine cx,90,130,0fh
				inc cx

				sub bl,1
				jnz loop13
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,125
loop14:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop14


				
				mov bl,5
				mov cx,125
loop15:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop15
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,130
loop16:
				DrawVirticalLine cx,50,85,02h
				inc cx

				sub bl,1
				jnz loop16
				
											
				mov bl,10
				mov cx,120
loop17:
				DrawVirticalLine cx,50,55,02h
				inc cx

				sub bl,1
				jnz loop17


				
				mov bl,5
				mov cx,130
loop18:
				DrawVirticalLine cx,90,130,0fh
				inc cx

				sub bl,1
				jnz loop18
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
														
				mov bl,5
				mov cx,135
loop19:
				DrawVirticalLine cx,50,55,02h
				inc cx

				sub bl,1
				jnz loop19


				
				mov bl,5
				mov cx,135
loop20:
				DrawVirticalLine cx,90,95,0fh
				inc cx

				sub bl,1
				jnz loop20
				
					
				mov bl,5
				mov cx,135
loop21:
				DrawVirticalLine cx,104,110,0fh
				inc cx

				sub bl,1
				jnz loop21
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h				
														
				mov bl,5
				mov cx,140
loop22:
				DrawVirticalLine cx,50,55,02h
				inc cx

				sub bl,1
				jnz loop22


				
				mov bl,5
				mov cx,140
loop23:
				DrawVirticalLine cx,90,95,0fh
				inc cx

				sub bl,1
				jnz loop23
				
					
				mov bl,5
				mov cx,140
loop24:
				DrawVirticalLine cx,104,110,0fh
				inc cx

				sub bl,1
				jnz loop24
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h						
														
				mov bl,4
				mov cx,147
loop25:
				DrawVirticalLine cx,50,85,02h
				inc cx

				sub bl,1
				jnz loop25


				
				mov bl,5
				mov cx,145
loop26:
				DrawVirticalLine cx,90,95,0fh
				inc cx

				sub bl,1
				jnz loop26
				
					
				mov bl,5
				mov cx,145
loop27:
				DrawVirticalLine cx,104,110,0fh
				inc cx

				sub bl,1
				jnz loop27
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,150
loop28:
				DrawVirticalLine cx,65,70,02h
				inc cx

				sub bl,1
				jnz loop28
				
					
				mov bl,5
				mov cx,150
loop29:
				DrawVirticalLine cx,90,130,0fh
				inc cx

				sub bl,1
				jnz loop29
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h				
				
				mov bl,5
				mov cx,155
loop30:
				DrawVirticalLine cx,65,70,02h
				inc cx

				sub bl,1
				jnz loop30
				
					
				mov bl,5
				mov cx,155
loop31:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop31
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h								
				
				mov bl,4
				mov cx,160
loop32:
				DrawVirticalLine cx,50,85,02h
				inc cx

				sub bl,1
				jnz loop32
				
					
				mov bl,5
				mov cx,160
loop33:
				DrawVirticalLine cx,90,95,04h
				inc cx

				sub bl,1
				jnz loop33
				
					
				mov bl,5
				mov cx,160
loop34:
				DrawVirticalLine cx,103,120,04h
				inc cx

				sub bl,1
				jnz loop34
				
					
				mov bl,5
				mov cx,160
loop35:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop35
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	

				
				mov bl,5
				mov cx,166
loop36:
				DrawVirticalLine cx,50,85,02h
				inc cx

				sub bl,1
				jnz loop36
				
				
											
				
				mov bl,5
				mov cx,165
loop37:
				DrawVirticalLine cx,90,95,04h
				inc cx

				sub bl,1
				jnz loop37
				
					
				mov bl,5
				mov cx,165
loop38:
				DrawVirticalLine cx,103,107,04h
				inc cx

				sub bl,1
				jnz loop38
				
					
				mov bl,5
				mov cx,165
loop39:
				DrawVirticalLine cx,115,120,04h
				inc cx

				sub bl,1
				jnz loop39
				
					
				mov bl,5
				mov cx,165
loop40:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop40
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,170
loop41:
				DrawVirticalLine cx,50,55,02h
				inc cx

				sub bl,1
				jnz loop41
				
					
				mov bl,5
				mov cx,170
loop42:
				DrawVirticalLine cx,65,70,02h
				inc cx

				sub bl,1
				jnz loop42
				
				
								
				mov bl,5
				mov cx,170
loop43:
				DrawVirticalLine cx,80,85,02h
				inc cx

				sub bl,1
				jnz loop43
				
				
											
				
				mov bl,5
				mov cx,170
loop44:
				DrawVirticalLine cx,90,95,04h
				inc cx

				sub bl,1
				jnz loop44
				
					
				mov bl,5
				mov cx,170
loop45:
				DrawVirticalLine cx,103,107,04h
				inc cx

				sub bl,1
				jnz loop45
				
					
				mov bl,5
				mov cx,170
loop46:
				DrawVirticalLine cx,115,120,04h
				inc cx

				sub bl,1
				jnz loop46
				
					
				mov bl,5
				mov cx,170
loop47:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop47
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	

				
				mov bl,5
				mov cx,175
loop48:
				DrawVirticalLine cx,50,55,02h
				inc cx

				sub bl,1
				jnz loop48
				
					
				mov bl,5
				mov cx,175
loop49:
				DrawVirticalLine cx,65,70,02h
				inc cx

				sub bl,1
				jnz loop49
				
				
								
				mov bl,5
				mov cx,175
loop50:
				DrawVirticalLine cx,80,85,02h
				inc cx

				sub bl,1
				jnz loop50
				
				
											
				
				mov bl,5
				mov cx,175
loop51:
				DrawVirticalLine cx,90,95,04h
				inc cx

				sub bl,1
				jnz loop51
				
					
				mov bl,5
				mov cx,175
loop52:
				DrawVirticalLine cx,103,107,04h
				inc cx

				sub bl,1
				jnz loop52
				
					
				mov bl,5
				mov cx,175
loop53:
				DrawVirticalLine cx,115,120,04h
				inc cx

				sub bl,1
				jnz loop53
				
					
				mov bl,5
				mov cx,175
loop54:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop54
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,180
loop55:
				DrawVirticalLine cx,50,55,02h
				inc cx

				sub bl,1
				jnz loop55
				
					
				mov bl,3
				mov cx,180
loop56:
				DrawVirticalLine cx,65,70,02h
				inc cx

				sub bl,1
				jnz loop56
				
				
								
				mov bl,5
				mov cx,180
loop57:
				DrawVirticalLine cx,80,85,02h
				inc cx

				sub bl,1
				jnz loop57
				
				
											
				
				mov bl,5
				mov cx,180
loop58:
				DrawVirticalLine cx,90,107,04h
				inc cx

				sub bl,1
				jnz loop58
				
					
				
					
				mov bl,5
				mov cx,180
loop59:
				DrawVirticalLine cx,115,120,04h
				inc cx

				sub bl,1
				jnz loop59
				
					
				mov bl,5
				mov cx,180
loop60:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop60
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h		
					
				mov bl,5
				mov cx,185
loop61:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop61
				
					
				mov bl,5
				mov cx,185
loop62:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop62
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,190
loop63:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop63
				
					
					
				mov bl,5
				mov cx,190
loop64:
				DrawVirticalLine cx,90,120,0fh
				inc cx

				sub bl,1
				jnz loop64
				
					
				mov bl,5
				mov cx,190
loop65:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop65
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,195
loop66:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop66
				
					
				mov bl,5
				mov cx,195
loop67:
				DrawVirticalLine cx,90,95,0fh
				inc cx

				sub bl,1
				jnz loop67
				
				
					
				mov bl,5
				mov cx,195
loop68:
				DrawVirticalLine cx,103,107,0fh
				inc cx

				sub bl,1
				jnz loop68
				
					
					
				mov bl,5
				mov cx,195
loop69:
				DrawVirticalLine cx,115,120,0fh
				inc cx

				sub bl,1
				jnz loop69
				
					
				mov bl,5
				mov cx,195
loop70:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop70
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,200
loop71:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop71
				
					
				mov bl,5
				mov cx,200
loop72:
				DrawVirticalLine cx,90,95,0fh
				inc cx

				sub bl,1
				jnz loop72
				
				
					
				mov bl,5
				mov cx,200
loop73:
				DrawVirticalLine cx,103,107,0fh
				inc cx

				sub bl,1
				jnz loop73
				
					
					
				mov bl,5
				mov cx,200
loop74:
				DrawVirticalLine cx,115,120,0fh
				inc cx

				sub bl,1
				jnz loop74
				
					
				mov bl,5
				mov cx,200
loop75:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop75
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				
				mov bl,5
				mov cx,205
loop76:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop76
				
					
				mov bl,5
				mov cx,205
loop77:
				DrawVirticalLine cx,90,95,0fh
				inc cx

				sub bl,1
				jnz loop77
				
				
					
				mov bl,3
				mov cx,205
loop78:
				DrawVirticalLine cx,103,107,0fh
				inc cx

				sub bl,1
				jnz loop78
				
					
					
				mov bl,5
				mov cx,205
loop79:
				DrawVirticalLine cx,115,120,0fh
				inc cx

				sub bl,1
				jnz loop79
				
					
				mov bl,5
				mov cx,205
loop80:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop80
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,210
loop81:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop81
				
				
					
				mov bl,5
				mov cx,210
loop82:
				DrawVirticalLine cx,90,95,0fh
				inc cx

				sub bl,1
				jnz loop82
				
					
					
				mov bl,5
				mov cx,210
loop83:
				DrawVirticalLine cx,115,120,0fh
				inc cx

				sub bl,1
				jnz loop83
				
					
				mov bl,5
				mov cx,210
loop84:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop84
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
				
				mov bl,5
				mov cx,215
loop85:
				DrawVirticalLine cx,80,85,0fh
				inc cx

				sub bl,1
				jnz loop85
				
				
					
				mov bl,5
				mov cx,215
loop86:
				DrawVirticalLine cx,90,95,0fh
				inc cx

				sub bl,1
				jnz loop86
				
					
					
				mov bl,5
				mov cx,215
loop87:
				DrawVirticalLine cx,115,120,0fh
				inc cx

				sub bl,1
				jnz loop87
				
					
				mov bl,5
				mov cx,215
loop88:
				DrawVirticalLine cx,125,130,0fh
				inc cx

				sub bl,1
				jnz loop88
				
				
				mov cx,00h
				mov dx,0f000h
				mov ah, 86h
				int 15h	
	
				mov bl,5
				mov cx,220
loop89:
				DrawVirticalLine cx,80,95,0fh
				inc cx

				sub bl,1
				jnz loop89
				
					
				mov bl,5
				mov cx,220
loop90:
				DrawVirticalLine cx,115,130,0fh
				inc cx

				sub bl,1
				jnz loop90

loop91:			

				
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
				lea dx,BYTE PTR msg
				int 21h
				
				mov cx,08h			;delay
				mov dx,4240h
				mov ah, 86h
				int 15h
				
				mov ah,1
				int 16h
				jz loop91
				
				
				;need to clear buffer
				mov ah,0
				int 16h
				
				
				mov ah,0  ;call video mode to clear screen
				mov al,13h
				int 10h
								
ENDM IntroPage 
;-----------------------------