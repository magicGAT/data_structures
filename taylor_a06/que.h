/*
 * que.h
 *
 *  Created on: Nov 1, 2019
 *      Author: gregorytaylor
 */

#ifndef QUE_H_
#define QUE_H_

#include <iostream>

using namespace std;

class Que
{
	private:
		int queue_front;
		int queue_back;
		int count;
		int queue_size;
		int * the_queue;
	public:

		Que(int);
		void intialize_queue();
		void into_queue(int);
		void leave_queue();
		int in_front();
		int in_back();
		bool is_empty();
		bool is_full();
		~Que();
};

#endif /* QUE_H_ */
