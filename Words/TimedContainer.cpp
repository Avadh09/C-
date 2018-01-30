#include "TimedContainer.h"

/**
 * Default constructor.
 */
TimedContainer::TimedContainer() : elapsed_time(0)
{
}

/**
 * Destructor.
 */
TimedContainer::~TimedContainer()
{
}

/**
 * Getter.
 * @return the elapsed time.
 */
long TimedContainer::get_elapsed_time() const { return elapsed_time; }

/**
 * Reset the elapsed time to 0.
 */
void TimedContainer::reset_elapsed_time() { elapsed_time = 0; }

/**
 * Increment the elapsed time.
 * @param usec the number of microseconds to increment.
 */
void TimedContainer::increment_elapsed_time(const long usec) { elapsed_time += usec; }
