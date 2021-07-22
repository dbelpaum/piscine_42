#include "ft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (dest);
}
