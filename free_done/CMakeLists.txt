cmake_minimum_required(VERSION 3.14)
project(free_done C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(free_done
        dop_funcs.c
        exception.c
        finds.c
        finds_2.c
        ft_atoi.c
        ft_bonus.c
        ft_bzero.c
        ft_celoe.c
        ft_flags.c
        ft_float.c
        ft_gotov.c
        ft_itoa.c
        ft_itoa_base.c
        ft_memalloc.c
        ft_memset.c
        ft_precision.c
        ft_print_bits.c
        ft_printf.c
        ft_putchar.c
        ft_putstr.c
        ft_save.c
        ft_stolbik.c
        ft_strdel.c
        ft_strdup.c
        ft_strjoin.c
        ft_strlen.c
        ft_strnew.c
        ft_strredup.c
        ft_strrejoin.c
        ft_strresub.c
        ft_strsub.c
        ft_width.c
        dop_funcs_2.c
        printf.h)
