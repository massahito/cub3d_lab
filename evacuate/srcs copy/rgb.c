#include "cub3d.h"

int	check_number_comma(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',' && !ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_number_space(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

static int	check_rgb_utils(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (check_number_space(arr[i]))
		{
			ft_double_ptr_free(arr);
			return (1);
		}
		if (ft_atoi(arr[i]) < 0 || 255 < ft_atoi(arr[i]))
		{
			ft_double_ptr_free(arr);
			return (1);
		}
		i++;
	}
	if (i != 3)
	{
		ft_double_ptr_free(arr);
		return (1);
	}
	return (0);
}

int	check_rgb(char *str)
{
	char	**arr;

	arr = ft_split(str, ',');
	if (!arr)
		malloc_err();
	if (check_rgb_utils(arr))
		return (1);
	ft_double_ptr_free(arr);
	return (0);
}

int	change_rgb(int *n)
{
	int	num;

	num = 0;
	num += (n[0] << 16);
	num += (n[1] << 8);
	num += (n[2]);
	return (num);
}