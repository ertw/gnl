#include "./libft/libft.h"
typedef struct	s_str 
{
	char	*s1;
	char	*s2;
}	t_str ;

int	main(void)
{
	t_str	str;
	str.s1 = "abcdef";
	str.s2 = "ghijkl";
	ft_putnbr(&str.s1[2] - str.s1);
	return (0);
}
