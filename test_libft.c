#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void	*ft_memcpy(void *restrict ptr, const void *restrict src, size_t len)
{
	char	*ptr_tmp;
	const char	*src_tmp;
	size_t	size;

	size = 0;
	if (ptr ==0  && src == 0)
		return (NULL);
	ptr_tmp = ptr;
	src_tmp = src;
	while (/*src_tmp != 0 && */size++ < len)
		*ptr_tmp++ = *src_tmp++;
	return (ptr);
}
void	*ft_memmove(void *ptr, const void *src, size_t len)
{
	char	*ptr_tmp;
	const char	*tmp;
	char	*src_tmp;
	size_t	size;

	size = 0;
	if (ptr == 0 && src == 0)
		return (NULL);
	src_tmp = (char *)malloc(sizeof(char) * len);
	ptr_tmp = ptr;
	tmp = src;
	while (size < len)
		src_tmp[size++] = *tmp++;
	size = 0;
	while (size++ < len)
		*ptr_tmp++ = *src_tmp++;
	return (ptr);
}
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char	*ft_strchr(char *str, char c)
{
	char	*ptr;
	int		index;

	ptr = str;
	index = 0;
	while (1)
	{
		if (ptr[index] == c)
			return (&ptr[index]);
		else if (ptr[index] == 0)
			return (NULL);
		index++;
	}
	return (NULL);
}

char	*ft_strrchr(char *str, char c)
{
	char	*ptr;
	int		index;
	char	*last_find;

	ptr = str;
	index = 0;
	last_find = 0;
	while (1)
	{
		if (ptr[index] == c)
			last_find = &ptr[index];
		if (ptr[index] == 0)
			break ;
		index++;
	}
	if (last_find == 0)
		return (NULL);
	else
		return (last_find);
}
void	*ft_memchr(const void *arr, int c, size_t len)
{
	const unsigned char	*ptr_arr;

	ptr_arr = (unsigned char *)arr;
	while (len--)
		if (*ptr_arr++ == c)
			return ((void *)--ptr_arr);
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	ptr_s1 = s1;
	ptr_s2 = s2;
	while (len--)
	{
		if(*ptr_s1 != *ptr_s2)
			return ((int)*ptr_s1 - (int)*ptr_s2);
		ptr_s1++;
		ptr_s2++;
	}
	return (0);
}
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const char	*ptr_str;
	const char	*ptr_tf;
	int	wordlen;

	ptr_str = str;
	wordlen = 0;
	if (!(*to_find) || len == 0)
		return ((char *)str);
	while (ptr_tf[wordlen] != 0)
		wordlen++;
	while (*ptr_str != 0 && len > 0)
	{
		ptr_tf = to_find;
		if (*ptr_str == *ptr_tf)
			while (*ptr_tf != 0 && *ptr_tf++ == *ptr_str++ && len > 0)
				len--;
		if (*ptr_tf == 0)
			return ((char *)ptr_str - wordlen - 1);
		ptr_str++;
		len--;
	}
	return (NULL);
}

int	save_cal(char *str, int index, int sign)
{
	int	save;

	save = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		save = save * 10 + sign * (str[index] - 48);
		index++;
	}
	return (save);
}

int	check_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	index;
	int	sign;
	int	save;

	index = 0;
	sign = 1;
	while ((check_space(str[index]) == 1))
		index++;
	if (str[index] == '-')
	{
		index++;
		sign *= -1;
	}
	else if (str[index] == '+')
		index++;
	save = save_cal(str, index, sign);
	return (save);
}

void	ft_zero(void *ptr, size_t len)
{
	char	*save_ptr;

	save_ptr = (char *)ptr;
	while (len--)
		*save_ptr++ = 0;
}
void	*ft_calloc(size_t len, size_t size)
{
	void	*alloc;
	size_t	index;

	alloc = (void *)malloc(size * len);
	ft_zero(alloc, len * size);
	return (alloc);
}
char	*ft_strdup(const char *src)
{
	char	*dup;
	const char *ptr_src;
	int		size;
	int	index;

	index= 0 ;
	ptr_src = src;
	size = 0;
	while (ptr_src[size] != '\0')
		size++;
	dup = (char *)malloc(sizeof(char) * (size + 1));
	dup[size] = 0;
	//while (index < size)
	//{
//		dup[index] = ptr_src[index];
//		index++;
//	}
	while (size--)
		dup[size] = ptr_src[size];
	return (dup);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	index;
	char	*alloc;
	const char	*ptr_str;

	index = 0;
	ptr_str = str;
	alloc = (char *)malloc(sizeof(char) * (len + 1));
	while (index < len && ptr_str[index + start] != 0)
	{
		alloc[index] = ptr_str[index + start];
		index++;
	}
	alloc[index] = 0;
	return (alloc);
}

int main()
{
	char	arr[20] = "asdfasdf";
	char	arr2[20] = "asdfasdz";
	char *ptr = "abcdef";
	int	a[10] = {10,1,2,3};
	char	arr3[11] = "--2147483647";
	int	*alloc;
	char	*arr4;


	arr4 = ft_substr(arr, 3, 100);
//	for (int i = 0; i < 10; i++)
//		printf("%d\t", alloc[i]);
	//arr4 = ft_strdup(arr);

	printf("arr4(arr) : %s\n\n", arr4);

//	for(int i = 0; i < 5; i++)
//		arr[i] = 31;
//	for(int i = 0; i < 5; i++)
//		arr[i + 5] = i + '0';
	printf("atoi : %d\n\n", atoi(arr3));
	printf("ft_atoi : %d\n\n", ft_atoi(arr3));
	printf("arr3 : %s\n\n", arr3);
	
	
	//int	ptr[10] = {4,5,6,7};

	//c = (char *)malloc(1);

	ft_memmove(arr,ptr,10);
	printf("%s\n", arr);
	printf("%p\n", arr);
	memmove(arr, ptr, 10);
	printf("%p\n", arr);
	printf("%s\n", arr);
	ft_memmove(a + 1, a, 10);
	for (int i = 0; i < 10; i++)
	printf("%d\t", a[i]);

	printf ("%c\n\n", ft_toupper((int)'a'));

	printf("%p\n\n", strrchr(arr, 'v'));
	printf("%p\n\n", ft_strrchr(arr, 'v'));
	printf("%p\n\n", memchr(arr, 'a', 10));
	printf("%p\n\n", ft_memchr(arr, 'a', 10));
	printf("%d\n\n", memcmp(arr, arr2, 10));
	printf("%d\n\n", ft_memcmp(arr, arr2, 10));
	printf("%s\n\n", strnstr(arr2, "s", 1));
	printf("%s\n\n", arr2);
	printf("%s\n\n", ft_strnstr(arr2, "s", 1));
}
