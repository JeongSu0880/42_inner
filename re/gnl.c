/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:42:27 by jungslee          #+#    #+#             */
/*   Updated: 2024/01/06 17:32:50 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void    *ft_memcpy(void *dest, const void *source, size_t num)
{
    unsigned char   *dest_tmp;
    unsigned char   *source_tmp;
    size_t          iter;

    iter = 0;
    dest_tmp = (unsigned char *)dest;
    source_tmp = (unsigned char *)source;
    if (dest == source)
        return (dest);
    while (iter < num)
    {
        *(dest_tmp + iter) = *(source_tmp + iter);
        iter++;
    }
    return (dest);
}

int	gnl_strlen(const char *str)
{
	int	cnt;

	if (str == NULL || *str == '\0')
		return (0);
	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int gnl_sub_str(char *dest, char *str, int start, int end)//dest에 str의 ㅣ내용을 start  부터 end까지 복사하는 함수
{
    // char    *ret;
    char    *dest_tmp;
    int     dest_len;
    int     i;

    i = 0;
    dest_len = gnl_strlen(dest);
    dest_tmp = (char *)malloc(sizeof(char) * (end - start + 2 + dest_len));//!!
    if (dest_tmp == NULL)
        return (-1);
    while (i < dest_len && dest_len != 0)
    {
        *(dest_tmp + i) = *(dest + i);
        i++;
    }
    while (i < (dest_len + end - start + 1))
    {
        *(dest_tmp + i) = *(str + i);
        i++;
    }
    if (dest != NULL)
        free(dest);
    *(dest_tmp + i) = '\0';
    dest = dest_tmp;
    return (i - 1);
}

int	check_nl(char *buf)
{
	int	idx;

	idx = 0;
	while (buf[idx] != '\0')
	{
		if (buf[idx] == '\n')
            return (idx);
		idx++;
	}
	return (-1);
}

t_fd    *search_fd(t_fd *fd_list, int fd)
{
    t_fd *new;

    if (fd_list == NULL)
    {
        new = (t_fd *)malloc(sizeof(t_fd));
        if (new == NULL)
            return (0);
        new->fd = fd;
        return (new);
    }
    while (1)
    {
        if (fd_list->fd == fd)
            return (fd_list);
        if (fd_list->back == NULL)
            break;
        fd_list = fd_list->back;
    }
    new = (t_fd *)malloc(sizeof(t_fd));
    if (new == NULL)
        return (0);
    new->fd = fd;
    new->front = fd_list;
    fd_list->back = new;
    return (new);
}

int renew_ret(char *buf, int cp_end, char *ret, int *len_sum)
{
    int  nl_idx;
    int  plus_len;

    // if (flag == 0)
    //     cp_end = gnl_strlen(buf) - 1;
    // else
    //     cp_end = BUFFER_SIZE - 1;
    // if (cp_end < 0)
    // {
    //     gnl_sub_str(ret->str + ret->len, buf, 0, 0);
    //     return (-2);
    // }
    // if (cp_end < 0)
    //     cp_end = -1;
    nl_idx = check_nl(buf);
    if (nl_idx != -1)
    {
        plus_len = gnl_sub_str(ret, buf, 0, nl_idx);
        if (plus_len < 0)
            return (-1);
        *len_sum = *len_sum + plus_len;
        return (nl_idx);
    }
    plus_len = gnl_sub_str(ret, buf, 0, cp_end);
    if (plus_len < 0)
        return (-1);
    *len_sum = *len_sum + plus_len; // 길이 갱신.   
    return (cp_end + 1); // nl이 없을 때는 버퍼 크기를 반환!
}

// void    init(t_ret *ret)
// {
//     ret = (t_ret *)malloc()
// }

char	*get_next_line(int fd)
{
    static t_fd *fd_list;
    t_fd    *now_fd;
    t_buf   unit;
    char   *ret;
    t_len   size;
    
    size.len_sum = 1;
    if (fd < 0)
        return (0);
    now_fd = search_fd(fd_list, fd);
    if (now_fd == NULL)
        return (0); // 이거 말고 에러나면 다 프리하는 코드 추가추가추가추ㅏㄱ
    //  해당  fd 파일 노드를 찾고, 없다면 뒤에 추가하고 무조건 노드 하나 반환
    // rest 확인하기
    if (now_fd->rest != NULL)
    {
        size.nl = renew_ret(now_fd->rest, gnl_strlen(now_fd->rest) - 1, ret, &size.len_sum);
        if (size.nl == -1)
            return (0); // 이거 말고 에러나면 다 프리하는 코드 추가차가추ㅏ가추ㅏㄱ
        //rest 갱신코드 추가
        else if (size.nl != gnl_strlen(now_fd->rest))
        {
            if (gnl_sub_str(now_fd->rest, now_fd->rest, size.nl, gnl_strlen(now_fd->rest) - 1) < 0)///여기 프리..프리..
                return (0);// 이거 말고 에러나면 다 프리하는 코드 추가추가추가ㅜㅊ가
        }
        else
        {
            free(now_fd->rest);
            now_fd->rest = NULL;
        }
    }
    while (1)
    {
        unit.read_len = read(fd, unit.buf, BUFFER_SIZE);
        // if (unit.read_len == 0)
        //     return (ret->str);
        size.nl = renew_ret(unit.buf, unit.read_len - 1, ret, &size.len_sum);
        if (size.nl == -2)
            return (ret);
        if (size.nl == -1)
            return (0);
        else if (size.nl != unit.read_len)
            return (ret);
    }
}


#include <fcntl.h>
#include <stdio.h>
// F5 디버깅 시작
// SHIFT+F5 디버깅 종료
// F9 브레이크 포인트
// F10 줄단위로 이동
// F11 프로시저단위로 이동
int main()
{
        int fd = open("test.txt", O_RDONLY);
        char *result;
        // //printf("%d\n", fd);
        // result = get_next_line(fd);
        // // write(1, result, gnl_strlen(result));
        // // printf("\n%zd\n\n", gnl_strlen(result));
        // free(result);
        // result = get_next_line(fd);
        // // write(1, result, gnl_strlen(result));
        // // printf("\n%zd\n\n", gnl_strlen(result));
        // free(result);
        // result = get_next_line(fd);
        // // write(1, result, gnl_strlen(result));
        // // printf("\n%zd\n\n", gnl_strlen(result));
        // free(result);
        // printf("%d\n", BUFFER_SIZE);
        result = get_next_line(fd);
        write(1, result, gnl_strlen(result));
    //printf("\n%zd\n\n", gnl_strlen(result));
        free(result);
        result = get_next_line(fd);
        //printf("len : %zd\n", gnl_strlen(result));
        write(1, result, gnl_strlen(result));
        free(result);
    // result = get_next_line(1);
    // write(1, result, gnl_strlen(result));
    // printf("\n%zd\n\n", gnl_strlen(result));
    // free(result);
    //system("leaks a.out");
}
