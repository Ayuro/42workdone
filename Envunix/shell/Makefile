#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/29 16:50:43 by flemaist          #+#    #+#              #
#*   Updated: 2016/05/20 16:07:58 by jhezard          ###   ########.fr       *#
#                                                                              #
#******************************************************************************#

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -g

NAME 		= minishell

#Directories
SRCS_PATH	= ./srcs/
OBJ_PATH	= ./objs/

#Sources
SRCS		+= $(SRCS_PATH)auto_complete.c
SRCS		+= $(SRCS_PATH)auto_complete2.c
SRCS		+= $(SRCS_PATH)auto_complete3.c
SRCS		+= $(SRCS_PATH)auto_complete_display.c
SRCS		+= $(SRCS_PATH)buffer_parse.c
SRCS		+= $(SRCS_PATH)call_builtins.c
SRCS		+= $(SRCS_PATH)clear_str.c
SRCS		+= $(SRCS_PATH)display_line.c
SRCS		+= $(SRCS_PATH)edit_line.c
SRCS		+= $(SRCS_PATH)edit_line_pairing.c
SRCS		+= $(SRCS_PATH)easy_list.c
SRCS		+= $(SRCS_PATH)easy_list2.c
SRCS		+= $(SRCS_PATH)exec_shrc.c
SRCS		+= $(SRCS_PATH)env_err.c
SRCS		+= $(SRCS_PATH)ft_args_env.c
SRCS		+= $(SRCS_PATH)ft_back_quote.c
SRCS		+= $(SRCS_PATH)ft_back_quote_tools.c
SRCS		+= $(SRCS_PATH)ft_err.c
SRCS		+= $(SRCS_PATH)ft_err_fd.c
SRCS		+= $(SRCS_PATH)ft_get_env.c
SRCS		+= $(SRCS_PATH)ft_go_home.c
SRCS		+= $(SRCS_PATH)ft_llredir.c
SRCS		+= $(SRCS_PATH)ft_logical_operator.c
SRCS		+= $(SRCS_PATH)ft_other.c
SRCS		+= $(SRCS_PATH)ft_other2.c
SRCS		+= $(SRCS_PATH)ft_other3.c
SRCS		+= $(SRCS_PATH)ft_other4.c
SRCS		+= $(SRCS_PATH)ft_other5.c
SRCS		+= $(SRCS_PATH)ft_other6.c
SRCS		+= $(SRCS_PATH)ft_other7.c
SRCS		+= $(SRCS_PATH)ft_other8.c
SRCS		+= $(SRCS_PATH)ft_other9.c
SRCS		+= $(SRCS_PATH)ft_export_temp.c
SRCS		+= $(SRCS_PATH)ft_pipe_tool.c
SRCS		+= $(SRCS_PATH)ft_pipe.c
SRCS		+= $(SRCS_PATH)ft_prompt.c
SRCS		+= $(SRCS_PATH)ft_prompt_2.c
SRCS		+= $(SRCS_PATH)ft_putint.c
SRCS		+= $(SRCS_PATH)ft_redirect.c
SRCS		+= $(SRCS_PATH)ft_sh1.c
SRCS		+= $(SRCS_PATH)ft_signal.c
SRCS		+= $(SRCS_PATH)ft_subshell.c
SRCS		+= $(SRCS_PATH)ft_subshell_2.c
SRCS		+= $(SRCS_PATH)ft_subshell_check.c
SRCS		+= $(SRCS_PATH)ft_temp.c
SRCS		+= $(SRCS_PATH)get.c
SRCS		+= $(SRCS_PATH)get2.c
SRCS		+= $(SRCS_PATH)get_clipboard.c
SRCS		+= $(SRCS_PATH)glob.c
SRCS		+= $(SRCS_PATH)glob_match.c
SRCS		+= $(SRCS_PATH)glob_tools.c
SRCS		+= $(SRCS_PATH)glob_tools2.c
SRCS		+= $(SRCS_PATH)help_logical_operator.c
SRCS		+= $(SRCS_PATH)history.c
SRCS		+= $(SRCS_PATH)history2.c
SRCS		+= $(SRCS_PATH)history3.c
SRCS		+= $(SRCS_PATH)history4.c
SRCS		+= $(SRCS_PATH)init_term.c
SRCS		+= $(SRCS_PATH)leaks.c
SRCS		+= $(SRCS_PATH)line.c
SRCS		+= $(SRCS_PATH)move.c
SRCS		+= $(SRCS_PATH)move2.c
SRCS		+= $(SRCS_PATH)norme.c
SRCS		+= $(SRCS_PATH)norme_err.c
SRCS		+= $(SRCS_PATH)norme_err2.c
SRCS		+= $(SRCS_PATH)norme_export.c
SRCS		+= $(SRCS_PATH)norme_pipe.c
SRCS		+= $(SRCS_PATH)norme_read.c
SRCS		+= $(SRCS_PATH)norme_redir.c
SRCS		+= $(SRCS_PATH)norme_redir2.c
SRCS		+= $(SRCS_PATH)pairing.c
SRCS		+= $(SRCS_PATH)pairing2.c
SRCS		+= $(SRCS_PATH)prompt_git.c
SRCS		+= $(SRCS_PATH)red_error.c
SRCS		+= $(SRCS_PATH)seg_signal.c
SRCS		+= $(SRCS_PATH)tabulation_tree.c
SRCS		+= $(SRCS_PATH)tabulation_tree_action.c
SRCS		+= $(SRCS_PATH)tabulation_tree_display.c
SRCS		+= $(SRCS_PATH)to_is.c
SRCS		+= $(SRCS_PATH)variable.c
SRCS		+= $(SRCS_PATH)variable_tool.c
SRCS		+= $(SRCS_PATH)read.c
SRCS		+= $(SRCS_PATH)read_flags.c
SRCS		+= $(SRCS_PATH)reset_and_clear.c
SRCS		+= $(SRCS_PATH)r_redir_help.c
SRCS		+= $(SRCS_PATH)r_detect_redir_out.c
SRCS		+= $(SRCS_PATH)r_detect_redir_in.c
SRCS		+= $(SRCS_PATH)r_redir.c
SRCS		+= $(SRCS_PATH)r_redir_error.c
SRCS		+= $(SRCS_PATH)r_redir_inout.c
SRCS		+= $(SRCS_PATH)is_script.c
SRCS		+= $(SRCS_PATH)is_script_2.c
SRCS		+= $(SRCS_PATH)shell_script.c
SRCS		+= $(SRCS_PATH)shell_script_2.c
SRCS		+= $(SRCS_PATH)shell_script_cdt.c
SRCS		+= $(SRCS_PATH)shell_script_if.c
SRCS		+= $(SRCS_PATH)shell_script_for.c
SRCS		+= $(SRCS_PATH)shell_script_until.c
SRCS		+= $(SRCS_PATH)shell_script_while.c
SRCS		+= $(SRCS_PATH)sc_first_method_for.c
SRCS		+= $(SRCS_PATH)sc_first_method_if.c
SRCS		+= $(SRCS_PATH)sc_first_method_if_2.c
SRCS		+= $(SRCS_PATH)sc_first_method_if_3.c
SRCS		+= $(SRCS_PATH)sc_tools_for.c
SRCS		+= $(SRCS_PATH)sc_check_for.c
SRCS		+= $(SRCS_PATH)sc_check_until.c
SRCS		+= $(SRCS_PATH)sc_check_while.c
SRCS		+= $(SRCS_PATH)sc_check_if.c
SRCS		+= $(SRCS_PATH)sc_check_if_two.c
SRCS		+= $(SRCS_PATH)sc_check_if_three.c
SRCS		+= $(SRCS_PATH)sc_check_if_four.c
SRCS		+= $(SRCS_PATH)ft_builtin_reset.c
SRCS		+= $(SRCS_PATH)ft_builtin_clear.c
SRCS		+= $(SRCS_PATH)ft_multi_del.c
SRCS		+= $(SRCS_PATH)red_error2.c

OBJS 		+= $(subst .c,.o,$(subst $(SRCS_PATH),$(OBJ_PATH),$(SRCS)))

LIBFT_DIR	= libft

DARK_RED		=	\033[38;5;52m
DARK_GREEN	=	\033[38;5;28m
UND					=	\033[4m
MSG_BOLD		=	\033[1m
MSG_STD 		=	\033[0m
CLEAR				=	\033[2K
UP 					=	\033[A
MID					=	\033[20C

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft
			@echo "$(MID)$(MSG_BOLD)$(DARK_RED)Prog Compilation: 	$(UND)$(DARK_GREEN)SUCCESSFUL!!!$(MSG_STD)"
			@$(CC) -o $(NAME) $(OBJS) -ltermcap libft/libft.a

$(OBJ_PATH)%.o: 	$(SRCS_PATH)%.c
					@mkdir -p -m 777 ./objs
					@gcc -o $@ -c $< $(CFLAGS)

.PHONY: all re clean fclean

clean:
		@make clean -C libft
		@/bin/rm -rf $(OBJ_PATH)
		@echo "$(CLEAR)$(MID)$(MSG_BOLD)$(DARK_RED)Prog Objs Deleted: 	$(UND)$(DARK_GREEN)YES!!!$(MSG_STD)"

fclean: clean
		@make fclean -C libft
		@/bin/rm -f $(NAME)
		@echo "$(CLEAR)$(MID)$(MSG_BOLD)$(DARK_RED)Prog Deleted: 	$(UND)$(DARK_GREEN)YES!!!$(MSG_STD)"

re: 	fclean all
