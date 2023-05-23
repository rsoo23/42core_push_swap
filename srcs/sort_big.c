/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:30:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/23 22:27:08 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Benchmarks:
100 (539 - 721 steps)
96 30 7 98 66 4 17 22 65 80 39 34 47 16 72 14 88 90 42 31 56 21 86 10 59 9 20 97 93 75 68 13 73 26 6 89 58 70 94 3 5 18 2 45 81 61 27 46 87 60 32 33 50 51 77 43 36 99 71 49 57 25 29 28 53 48 76 23 62 64 85 8 74 44 83 12 15 91 78 40 41 38 92 52 1 35 24 84 100 63 79 11 69 54 95 67 37 82 19 55
Mine: 781

500 (3923 - 7197)
489 410 420 429 86 285 94 471 134 368 185 256 117 322 14 182 463 252 5 364 58 87 38 8 99 379 488 462 492 243 314 218 344 442 159 339 102 269 493 40 169 450 26 325 146 147 401 112 460 108 446 390 250 491 262 296 498 259 461 348 166 50 412 437 174 97 176 175 399 267 305 16 292 469 189 478 451 394 63 418 232 1 242 402 458 209 415 331 366 119 435 37 222 266 395 214 17 235 383 197 393 421 439 251 244 183 145 216 82 180 360 308 467 377 414 464 120 289 253 470 422 258 141 2 245 277 24 69 163 453 434 75 353 500 281 288 445 494 456 391 25 128 193 287 385 21 268 228 31 90 261 200 188 396 326 190 220 123 47 144 319 355 148 425 66 171 447 234 310 239 12 313 307 370 231 55 223 426 389 272 398 208 56 468 106 7 192 131 384 477 392 315 482 51 100 324 54 299 165 23 293 111 221 372 329 433 304 48 342 282 367 207 301 184 497 213 61 96 443 230 241 205 187 164 212 3 466 338 286 484 448 330 4 311 400 263 438 39 264 334 101 15 177 57 127 284 211 323 294 93 476 155 72 440 203 62 356 387 340 275 152 249 246 280 215 397 381 161 236 85 11 283 431 20 332 465 68 88 427 60 495 124 53 59 136 375 424 358 312 6 499 83 428 335 36 423 178 343 361 168 156 125 238 405 194 143 403 346 219 254 352 341 133 64 52 376 452 317 49 179 441 475 409 486 137 71 270 481 158 248 347 454 404 487 139 354 181 84 78 320 29 121 92 359 89 336 80 374 333 162 345 378 35 170 201 371 32 357 157 116 416 217 290 70 237 388 140 76 204 318 149 129 65 114 138 407 150 337 309 122 115 210 362 297 298 18 328 153 225 490 419 81 473 483 34 240 135 46 365 233 408 28 160 271 186 30 276 382 173 278 110 43 369 316 260 41 485 430 27 206 98 274 279 386 202 306 167 132 79 291 406 104 105 130 227 107 9 351 444 257 273 42 303 373 118 10 247 109 198 44 73 113 302 457 154 195 496 255 172 191 479 295 19 417 474 45 67 196 74 95 321 199 436 349 350 380 472 455 411 449 300 480 327 265 224 103 77 22 226 432 126 229 91 33 13 363 151 142 459 413
Mine: 6890
*/

void	find_top_bottom_index(t_dlist *stack_a, t_info *info)
{
	t_dlist		*head;
	t_dlist		*tail;

	head = stack_a;
	tail = ft_dlstlast(stack_a);
	if (info->size_b == info->upper_lim)
	{
		info->part_size /= 2;
		info->upper_lim += info->part_size;
	}
	while (head)
	{
		if (head->index <= info->upper_lim)
			break ;
		info->top_pos++;
		head = head->next;
	}
	while (tail)
	{
		if (tail->index <= info->upper_lim)
			break ;
		info->bot_pos++;
		tail = tail->prev;
	}
}

void	rot_a_num_to_head(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	if (info->bot_pos >= info->top_pos)
		while (info->top_pos-- > 0)
			rotate('a', stack_a, stack_b);
	else if (info->bot_pos < info->top_pos)
		while (info->bot_pos-- > 0)
			rev_rotate('a', stack_a, stack_b);
}

void	push_a_sequence(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	t_dlist *tail_b;

	info->search = info->size_b;
	while (info->search > 0)
	{
		tail_b = ft_dlstlast(*stack_b);
		info->pos = 0;
		while (tail_b && info->search != tail_b->index)
		{
			info->pos++;
			tail_b = tail_b->prev;
		}
		// printf("managed to find: %d\n", info->search);
		opt_rot('b', info, stack_a, stack_b);
		push('a', stack_a, stack_b);
		info->search--;
		info->size_b--;
	}
}

// void	push_a_sequence(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
// {
// 	while (info->size_b > 0)
// 	{
// 		if (ft_dlstlast(*stack_b)->index - ft_dlstlast(*stack_a)->index == 1)
// 		{
// 			push('a', stack_a, stack_b);
// 			rotate('a', stack_a, stack_b);
// 			info->size_b--;
// 		}
// 		else if ((*stack_a)->index - ft_dlstlast(*stack_b)->index >= 1)
// 		{
// 			if (ft_dlstlast(*stack_a)->index > ft_dlstlast(*stack_b)->index)
// 				while ((*stack_a)->index - ft_dlstlast(*stack_b)->index != 1 
// 				&& ft_dlstlast(*stack_a)->index != info->input_size)
// 					rev_rotate('a', stack_a, stack_b);
// 			push('a', stack_a, stack_b);
// 			info->size_b--;
// 		}
// 		else
// 			while((*stack_a)->index < ft_dlstlast(*stack_b)->index)
// 				rotate('a', stack_a, stack_b);
// 		while ((*stack_a)->index - ft_dlstlast(*stack_a)->index == 1)
// 			rev_rotate('a', stack_a, stack_b);
// 		while ((*stack_a)->index - ft_dlstlast(*stack_a)->index == 1)
// 			rotate('a', stack_a, stack_b);
// 	}
// 	while ((*stack_a)->index != 1)
// 		rev_rotate('a', stack_a, stack_b);
// }

/*
1. range: 0 - 50: part_size = 100 / 2, upperlim = 50, pivot = (0 + 50) = 25, 
2. range: 50 - 75: part_size = 50 / 2, upperlim += part_size = 75, pivot =  (50 + 75) / 2 = 62.5,
3. range: 75 - 87.5: part_size = 25 / 2, upperlim = 87.5, pivot = (75 + 87.5) = 81.25, 

(upperlimit - partsize + upperlimit) / 2
*/

void	push_b_sequence(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	push('b', stack_a, stack_b);
	info->pivot = (2 * info->upper_lim - info->part_size) / 2;
	// printf("pivot:%d, partsize: %d\n", info->pivot, info->part_size);
	if (ft_dlstlast(*stack_b)->index <= info->pivot)
		rotate('b', stack_a, stack_b);
}

void	sort_big(t_dlist **stack_a, t_dlist **stack_b, int size_a)
{
	t_info	*info;
	
	info = malloc(sizeof(t_info));
	init_info(info, size_a);
	assign_index(stack_a, size_a);
	// assign_part_size(info);
	while (info->size_a > 3)
	{
		info->top_pos = 0;
		info->bot_pos = 1;
		find_top_bottom_index(*stack_a, info);
		rot_a_num_to_head(stack_a, stack_b, info);
		push_b_sequence(stack_a, stack_b, info);
		info->size_b++;
		info->size_a--;
	}
	sort_small(stack_a, stack_b);
	// int i = 0;
	// while ((*stack_b))
	// {
	// 	i++;
	// 	printf("%d:%d\n", i, ((*stack_b))->index);
	// 	(*stack_b) = ((*stack_b))->next;
	// }
	push_a_sequence(stack_a, stack_b, info);
	free(info);
}
