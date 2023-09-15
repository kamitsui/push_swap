/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:52:04 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/15 16:32:59 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//void merge(t_stack *stack_a, t_stack *stack_b, int low, int mid, int high) {
//void merge(t_stack *stack_a, t_stack *stack_b, int low, int high) {
//    int i = low;
//    //int j = mid + 1;
//    int j = low + (high - low) / 2 + 1;
//    int k = low;
//
//    while (i <= mid && j <= high) {
//        if (stack_a->data[i] <= stack_a->data[j]) {
//            //temp_stack->data[k] = stack->data[i];
//			instruct_pa(stack_b, stack_a->data);
//            i++;
//        } else {
//            //temp_stack->data[k] = stack->data[j];
//			
//            j++;
//        }
//        k++;
//    }
//
//    while (i <= mid) {
//        temp_stack->data[k] = stack->data[i];
//        i++;
//        k++;
//    }
//
//    while (j <= high) {
//        temp_stack->data[k] = stack->data[j];
//        j++;
//        k++;
//    }
//
//    for (int t = low; t <= high; t++) {
//        stack->data[t] = temp_stack->data[t];
//    }
//}
//
//void merge_sort(t_stack *stack_a, t_stack *stack_b, int low, int high)
//{
//    if (low < high) {
//        int mid = low + (high - low) / 2;
//
//        merge_sort(stack_a, stack_b, low, mid);
//        merge_sort(stack_a, stack_b, mid + 1, high);
//
//        //merge(stack, temp_stack, low, mid, high);
//        merge(stack_a, stack_b, low, high);
//    }
//}
