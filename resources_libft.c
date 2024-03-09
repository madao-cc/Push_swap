#include "push_swap.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	size;

	if ((int)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}

char	*ft_strdup(char *str)
{
	char	*result;
	size_t	i;

	i = ft_strlen(str) + 1;
	result = malloc(i);
	if (!result)
		return (NULL);
	ft_memcpy(result, str, i);
	return (result);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!s && !d)
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}
