/*
 * main.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: gregorytaylor
 */

#include <iostream>
#include <chrono>
#include <stdlib.h>

#include "que.h"

using namespace std;

// random number from 1 - 100 function prototype
int rando();

int main()
{
	// OPTIONAL QUEUE TESTING
	/*
	Que test(5);

	cout << "Test if queue is empty: ";
	if (test.is_empty())
	{
		cout << "TRUE";
	}
	else
	{
		cout << "FALSE";
	}
	cout << endl;

	cout << "Adds 1 to queue" << endl;
	test.into_queue(1);
	cout << "Front: " << test.in_front() << endl;
	cout << "Back: " << test.in_back() << endl;

	cout << "Adds 2 to queue" << endl;
	test.into_queue(2);
	cout << "Front: " << test.in_front() << endl;
	cout << "Back: " << test.in_back() << endl;

	cout << "Adds 3 to queue" << endl;
	test.into_queue(3);
	cout << "Front: " << test.in_front() << endl;
	cout << "Back: " << test.in_back() << endl;

	cout << "Adds 4 to queue" << endl;
	test.into_queue(4);
	cout << "Front: " << test.in_front() << endl;
	cout << "Back: " << test.in_back() << endl;

	cout << "Adds 5 to queue" << endl;
	test.into_queue(5);
	cout << "Front: " << test.in_front() << endl;
	cout << "Back: " << test.in_back() << endl;

	cout << "Test if queue is full: ";
	if (test.is_full())
	{
		cout << "TRUE";
	}
	else
	{
		cout << "FALSE";
	}
	cout << endl;

	cout << "Removes 1 from queue" << endl;
	test.leave_queue();
	cout << "Front: " << test.in_front() << endl;
	cout << "Back: " << test.in_back() << endl;

	cout << "Removes 2 from queue" << endl;
	test.leave_queue();
	cout << "Front: " << test.in_front() << endl;
	cout << "Back: " << test.in_back() << endl;

	cout << "Removes 3 from queue" << endl;
	test.leave_queue();
	cout << "Front: " << test.in_front() << endl;
	cout << "Back: " << test.in_back() << endl;

	cout << "Removes 4 from queue" << endl;
	test.leave_queue();
	cout << "Front: " << test.in_front() << endl;
	cout << "Back: " << test.in_back() << endl;

	cout << "Removes 5 from queue" << endl;
	test.leave_queue();
	 // PROBLEM HERE
	 // cout << "Front: " << test.in_front() << endl;
	 // cout << "Back: " << test.in_back() << endl;

	cout << "Test if queue is empty: ";
	if (test.is_empty())
	{
		cout << "TRUE";
	}
	else
	{
		cout << "FALSE";
	}
	*/

	// variable declarations
	int user_queue_length, clock_ticks, generated, began_processing, processed, unprocessed, arrival_rate, exit_rate, timer;
	bool in_progress;

	// prompts for user inputs
	cout << "Please enter 'waitroom' size: ";
	cin >> user_queue_length;

	cout << "Please enter probability of generating a new transaction per tick: ";
	cin >> arrival_rate;

	cout << "Please enter the probability of completing a transaction: ";
	cin >> exit_rate;

	cout << "Enter the duration of the simulation (in clock ticks): ";
	cin >> clock_ticks;

	// queue generation
	Que hospital_waitroom(user_queue_length);

	// condition initialization
	timer = 0;
	srand(66);
	in_progress = false;
	generated = 0;
	began_processing = 0;
	processed = 0;
	unprocessed = 0;

	cout << rando() << endl;
	cout << rando() << endl;
	cout << rando() << endl;
	cout << rando() << endl;
	cout << rando() << endl;
	cout << rando() << endl;

	// processing loop
	while (timer < clock_ticks)
	{
		// arrivals
		if (rando() <= arrival_rate)
		{
			hospital_waitroom.into_queue(33);
			generated++;
		}

		// patient processing
		if (in_progress == false)
		{
			if (!hospital_waitroom.is_empty())
			{
				hospital_waitroom.leave_queue();
				in_progress = true;
				began_processing++;
			}
		}

		// patient discharge
		if (in_progress == true)
		{
			if (rando() <= exit_rate)
			{
				in_progress = false;
				processed++;
			}
		}

		timer++;
	}

	// reports results to console
	cout << "---.OUTCOME REPORT.---" << endl;
	cout << "# clock ticks: " << clock_ticks << endl;
	cout << "# patients whom entered the line: " << generated << endl;
	cout << "# of patients whom began treatment: " << began_processing << endl;
	cout << "# of patients successfully treated and discharged: " << processed << endl;
	if (in_progress == true)
		cout << "1 patient currently in treatment!" << endl;
	cout << "# of patients still in the line: " << generated - processed << endl;

	return 0;
}

int rando()
{
	int result;
	result = (rand() % (100 - 1 + 1)) + 1;

	return result;
}

