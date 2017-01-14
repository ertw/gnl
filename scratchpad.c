#include "./libft/libft.h"
#include <stdio.h>

int	ft_lpstrlen(char *str)
{
	return ((int)*str);
}

char	*ft_strnjoin(char *s1, size_t n1, char *s2, size_t n2)
{
	if (!(ft_memalloc(sizeof(s1) * (n1 + n2 + 1))))
		return (NULL);
	return (s1);
}

char	*ft_substr(char *str, size_t start, size_t end)
{
	char	*substring;

	if (!str)
		return (NULL);
	substring = ft_strncpy(substring, str + start, end - start);
	printf("%p\n", &str + start);
	printf("%zu\n", end - start);
	return (substring);
}

int	main(void)
{
	char	s1[6] = "abcde\0";
	char	s2[6] = "fghij\0";
	size_t	len = 1253;
	
	--len;
	len |= len>> 1;
	len|= len>> 2;
	len|= len>> 4;
	len|= len>> 8;
	len|= len>> 16;
	++len;
	ft_putnbr(len);
//	ft_putendl(ft_strjoin(s1, ft_substr(s2, 1, 3)));
//	ft_putnbr(&str.s1[2] - str.s1);
//	ft_putendl(ft_strjoin(str.s1, ft_memmove(str.s2, str.s2, 1)));
	return (0);
}
