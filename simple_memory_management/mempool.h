/*
 * =====================================================================================
 *
 *       Filename:  mempool.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/26/2021 08:01:26 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _MEMPOOL_H_
#define _MEMPOOL_H_

void pool_init(void);
void *pool_malloc(int nbytes);
void pool_free(void *p);
void pool_info(void);

#endif //_MEMPOOL_H_ end

