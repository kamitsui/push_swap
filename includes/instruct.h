/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:08:40 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/30 17:16:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file instruct.h
 * @brief Define instruction functions for stack operations
 */
#ifndef INSTRUCT_H
# define INSTRUCT_H

void	push_data(t_stack *dst, t_stack *src);
void	swap_one(t_stack *target);
void	swap_two(t_stack *target1, t_stack *target2);

/*
 * ---------------- instruction functions ----------------
 */

/**
 * @brief execute ss & output "ss\n"
 */
void	instruct_ss(t_stack *target1, t_stack *target2);

/**
 * @brief execute ( pa | pb ) & output ( "pa\n" | "pb\n" )
 */
void	instruct_px(t_stack *dst, t_stack *src);

/**
 * @brief execute ( ra | rb ) & output ( "ra\n" | "rb\n" )
 */
void	instruct_rx(t_stack *target);

/**
 * @brief execute rr & output "rr\\n"
 */
void	instruct_rr(t_stack *target1, t_stack *target2);

/**
 * @brief execute ( ra | rb ) & output ( "rra\n" | "rrb\n" )
 */
void	instruct_rrx(t_stack *target);

/**
 * @brief execute rrr & output "rrr\\n"
 */
void	instruct_rrr(t_stack *target1, t_stack *target2);

/*
 * ---------------- execute instruction functions ----------------
 */

/**
 * @brief execute instruction ss
 */
void	execute_ss(t_stack *target1, t_stack *target2);

/**
 * @brief execute instruction ( pa | pb )
 */
//void	execute_px(t_stack *dst, t_stack *src);
void	execute_pa(t_stack *stack_a, t_stack *stack_b);
void	execute_pb(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief execute instruction ( ra | rb )
 */
//void	execute_rx(t_stack *stack);
void	execute_ra(t_stack *stack_a, t_stack *stack_b);
void	execute_rb(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief execute instruction rr
 */
void	execute_rr(t_stack *target1, t_stack *target2);

/**
 * @brief execute instruction ( rra | rrb )
 */
//void	execute_rrx(t_stack *stack);
void	execute_rra(t_stack *stack_a, t_stack *stack_b);
void	execute_rrb(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief execute instruction rrr
 */
void	execute_rrr(t_stack *target1, t_stack *target2);

/*
 * ---------------- execute instruction functions ----------------
 */

/**
 * @brief Function pointer for collecting is_instruction_**\n
 * (search_type_instruction use this)
 */
typedef void	(*t_f_execute)(t_stack *target1, t_stack *target2);

#endif
