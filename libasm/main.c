/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:38:09 by dlucio            #+#    #+#             */
/*   Updated: 2021/01/03 03:40:01 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "libasm.h"


#include <sys/types.h>
#include <sys/stat.h>

int	main(void)
{
	
	char *str;
	int	i;
	char *dst;
	char *src;
	char *s1;
	char *s2;
	char c;
	char *buf;
	int	fd;

	str = strdup("milk");
	i = ft_strlen(str);
	printf("ft_strlen test: \n%d \n \n", i);

	dst = strdup("silk");
	src = strdup("lamp");
	printf("ft_strcpy test: \n");
	printf("dst: %s \n", dst);
	printf("src: %s \n", src);
	dst = ft_strcpy(dst, src);
	printf("result %s \n", dst);

	printf("\nft_strcmp test:\n");
	
	s1 = strdup("milc\n");
	s2 = strdup("milc\n");
	printf("dst = %s", s1);
	printf("src = %s", s2);
	i = ft_strcmp(s1, s2);
	printf("result = %d \n \n", i);

	s1 = strdup("milc\n");
	s2 = strdup("milb\n");
	printf("dst = %s", s1);
	printf("src = %s", s2);
	i = ft_strcmp(s1, s2);
	printf("result = %d \n \n", i);

	s1 = strdup("milc\n");
	s2 = strdup("mild\n");
	printf("dst = %s", s1);
	printf("src = %s", s2);
	i = ft_strcmp(s1, s2);
	printf("result = %d \n \n", i);

	printf("\nft_write test:\n");
	c = 'm';
	str = strdup("milk");
	ft_write(1, &c, 1);
	printf("\n c = %c \n", c);

	printf("\nft_strdup test: \n");
	str = strdup("milk");
	printf("   strdup => milk = %s \n", str);
	str = ft_strdup("milk");
	printf("ft_strdup => milk = %s \n", str);
	
	buf = malloc(sizeof(char) * (2 + 1));
	printf("\nft_read test: \n read text.txt file -> \n");
	fd = open("text.txt", O_RDONLY);
	// fd = open("text.txt", O_RDONLY);
	//  printf("fd = %d", fd);
	if (fd  == -1)
		printf("Cannot open file.\n");
	i = read(fd, buf, 2);
	buf[2] = '\0';
	if (i == -1)
	{
		printf("Cannot read file, read = %d \n", i);
	}
	else
	{
		printf("file loaded correct:");
		printf("buf = %s", buf);
	}

	return(0);
}
