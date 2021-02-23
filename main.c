/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 13:22:38 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/15 12:18:18 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "libasm.h"

int main(void)
{
    char	str1[] = "pannekoek";
	char	str2[] = "";
	char	*str3 = NULL;
    char    *str4 = "appelflap";
    char    *str5 = "paardenbloempje";
    char    str7[] = "qwertyuiopasdfghjklzxcvbnm";
    char    str8[] = "mnbvcxzlkjhgfdsapoiuytrewq";
    char    *str9 = "appelflap";
    char    *str10 = "";
    char    *str11 = "";
    char    *str12 = NULL;
    char    buf1[50];
    char    buf2[50];
    char    buf3[50];
    int     fd;
    int     ret;
    size_t  res;
    printf("FT_STRLEN:\n");
    printf("FT_STRLEN LONG STRING:\n");
    printf("lenght of string str7(%s) is %zu\n\n", str7, ft_strlen(str7));
    printf("FT_STRLEN EMPTY STRING:\n");
    printf("lenght of string str10(%s) is %zu\n\n", str10, ft_strlen(str10));

    printf("FT_STRCPY:\n");
    printf("FT_STRCPY EMPTY STRING:\n");
	printf("before: str1: %s | str2: %s | str3: %p\n", str1, str2, str3);
	str3 = ft_strcpy(str1, str2);
	printf("after: str1: %s | str2: %s | str3: %p\n\n", str1, str2, str3);
    str3 = NULL;

    printf("FT_STRCPY LONG STRING:\n");
    printf("before: str7: %s | str8: %s | str3: %p\n", str7, str8, str3);
	str3 = ft_strcpy(str7, str8);
	printf("after: str7: %s | str8: %s | str3: %p\n\n", str7, str8, str3);

    printf("FT_STRCMP:\n");
    printf("FT_STRCMP EQUAL:\n");
    ret = ft_strcmp(str4, str9);
    printf("comparison between str4 and str9 is %d\n", ret);
    printf("FT_STRCMP S1 GREATER THAN S2:\n");
    ret = ft_strcmp(str5, str4);
    printf("comparison between str5 and str4 is %d\n", ret);
    printf("FT_STRCMP S1 LESSER THAN S2:\n");
    ret = ft_strcmp(str4, str5);
    printf("comparison between str4 and str5 is %d\n", ret);
    printf("FT_STRCMP S1 EMPTY STRING:\n");
    ret = ft_strcmp(str10, str9);
    printf("comparison between str10 and str9 is %d\n", ret);
    printf("FT_STRCMP S2 EMPTY STRING:\n");
    ret = ft_strcmp(str9, str10);
    printf("comparison between str9 and str10 is %d\n", ret);
    printf("FT_STRCMP TWO EMPTY STRINGS:\n");
    ret = ft_strcmp(str10, str11);
    printf("comparison between str10 and str11 is %d\n\n", ret);

    printf("FT_STRDUP:\n");
    printf("FT_STRDUP WITH EMPTY STRING:\n");
    printf("str12 before ft_strdup: %s\n", str12);
    str12 = ft_strdup(str4);
    printf("str12 after ft_strdup: %s\n\n", str12);
    printf("FT_STRDUP WITH LONG STRING:\n");
    printf("str12 before ft_strdup: %s\n", str12);
    str12 = ft_strdup(str7);
    printf("str12 after ft_strdup: %s\n\n", str12);

	printf("FT_WRITE:\n");
    printf("FT_WRITE FROM STDIN:\n");
	res = ft_write(0, str4, ft_strlen(str4));
	printf(" <- Written string | str_to_write: %s | errno: %i | bytes written: %ld\n\n", str4, errno, res);
    printf("FT_WRITE FROM STDOUT:\n");
	res = ft_write(1, str5, ft_strlen(str5));
	printf(" <- Written string | str_to_write: %s | errno: %i | bytes written: %ld\n\n", str5, errno, res);
    printf("FT_WRITE WITH OPEN FILEDESCRIPTOR:\n");
    fd = open("read.txt", O_WRONLY);
	res = ft_write(fd, "abcdefghijklmnopqrstuvwxyz", 27);
	printf("Check read.txt for written string | str_to_write: %s | errno: %i | bytes written: %ld\n\n", "abcdefghijklmnopqrstuvwxyz", errno, res);
    printf("FT_WRITE WITH BAD FILEDESCRIPTOR:\n");
	res = ft_write(-1, str5, strlen(str5));
	perror("perror:");
	printf(" <- Written string | str_to_write: %s | errno: %i | bytes written: %ld\n\n", str5, errno, res);
    errno = 0;
    
    printf("FT_READ:\n");
    printf("FT_READ FROM STDIN:\n");
    res = ft_read(0, buf3, 50);
    printf("^^ text read | bytes read: %ld | errno: %i\n\n", res, errno);
    printf("FT_READ WITH OPEN FILEDESCRIPTOR:\n");
    fd = open("read.txt", O_RDONLY);
    res = ft_read(fd, buf1, 50);
    printf("bytes read: %ld | text read: %s | errno: %i\n\n", res, buf1, errno);
    printf("FT_READ WITH BAD FILEDESCRIPTOR:\n");
    res = ft_read(-1, buf2, 50);
    perror("write error");
    printf("bytes read: %ld | text read: %s | errno: %i\n\n", res, buf2, errno);
    return (0);
}