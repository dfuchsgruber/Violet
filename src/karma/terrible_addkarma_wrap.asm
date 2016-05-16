@this function wraps addkrama so we can acess r5 (which is not meant to be a transfer reg) as transfer reg
.align 2
.thumb

.global special_addkarma_wrap

.thumb_func
special_addkarma_wrap:
push {lr}
mov r0, r5
bl addkarma
pop {pc}
