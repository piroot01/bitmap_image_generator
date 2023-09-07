#ifndef MANAGER_TASK_INCLUDED
#define MANAGER_TASK_INCLUDED


#include "managers/task.h"
#include "parameters/manager_task_parameters.h"
#include "chunk/image_chunk.h"
#include "image_objects/pixel_set.h"
#include <vector>


/**
* @class ManagerTask
* @brief Implements one threads task
*/
class ManagerTask : public Task
{
public:

    /**
    * @brief run
    * @parame parameters accepted as copy
    * chunkNum essentially id of the thread
    */
    static std::shared_ptr<ImageChunk> run(ManagerTaskParameters parameters, const uint32_t chunkNum);

};


#endif
