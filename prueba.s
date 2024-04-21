##################
# Seccion de datos
	.data

$str1:
	.asciiz "Inicio del programa\n"
$str2:
	.asciiz "a"
$str3:
	.asciiz "\n"
$str4:
	.asciiz "No a y b\n"
$str5:
	.asciiz "c = "
$str6:
	.asciiz "\n"
$str7:
	.asciiz "MEDIO"
$str8:
	.asciiz "\n"
$str9:
	.asciiz "d = "
$str10:
	.asciiz "\n"
$str11:
	.asciiz "FIN"
$str12:
	.asciiz "\n"
_a:
	.word 0
_b:
	.word 0
_c:
	.word 0
_d:
	.word 0

##################
# Seccion de codigo
	.text
	.globl main
main:
	li $t0,0
	sw $t0,_a
	li $t0,0
	sw $t0,_b
	li $t0,5
	li $t1,2
	add $t0,$t0,$t1
	li $t1,2
	sub $t0,$t0,$t1
	sw $t0,_c
	li $t0,7
	sw $t0,_d
	li $v0,4
	la $a0,$str1
	syscall
	lw $t0,_a
	beqz $t0,$label_4
	li $v0,4
	la $a0,$str2
	syscall
	li $v0,4
	la $a0,$str3
	syscall
	b $label_5

$label_4:
	lw $t1,_b
	beqz $t1,$label_2
	li $v0,4
	la $a0,$str4
	syscall
	b $label_3

$label_2:

$label_0:
	lw $t2,_c
	beqz $t2,$label_1
	li $v0,4
	la $a0,$str5
	syscall
	lw $t3,_c
	li $v0,1
	move $a0,$t3
	syscall
	li $v0,4
	la $a0,$str6
	syscall
	lw $t3,_c
	li $t4,2
	sub $t3,$t3,$t4
	li $t4,1
	add $t3,$t3,$t4
	sw $t3,_c
	b $label_0

$label_1:

$label_3:

$label_5:
	li $v0,4
	la $a0,$str7
	syscall
	li $v0,4
	la $a0,$str8
	syscall
	lw $t3,_d

$label_6:
	li $v0,4
	la $a0,$str9
	syscall
	lw $t3,_d
	li $v0,1
	move $a0,$t3
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	lw $t3,_d
	li $t4,1
	sub $t3,$t3,$t4
	sw $t3,_d
	lw $t3,_d
	beqz $t3,$label_7
	b $label_6

$label_7:
	li $v0,4
	la $a0,$str11
	syscall
	li $v0,4
	la $a0,$str12
	syscall

##################
# Fin de la ejecucion
	li $v0, 10
	syscall
