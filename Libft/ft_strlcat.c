#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;

	dst_size = ft_strlen(dst);
	if (size < dst_size)
		return (size);
	i = 0;
	while (i < size - dst_size - 1)
	{
		dst[dst_size + i] = src[i];
	}
	dst[dst_size + i] = '\0';
	return (dst_size + ft_strlen(src));
}