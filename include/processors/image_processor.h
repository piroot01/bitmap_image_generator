#ifndef IMAGE_PROCESSOR_INCLUDED
#define IMAGE_PROCESSOR_INCLUDED


#include "image_objects/point_set.h"
#include "image_objects/drawable_objects_queue.h"
#include "image/image.h"
#include "chunk/image_chunk.h"
#include <memory>


#define MINIMAL_CHUNK_SIZE 1024


class ImageProcessor
{
public:
    explicit ImageProcessor(const Image& image, const DrawableObjectsQueue& queue, const std::shared_ptr<PointSet> pPointSet);
    void process();

private:
    const Image* _image;
    const DrawableObjectsQueue* _queue;
    const std::shared_ptr<PointSet> _pPointSet;

    ImageChunk _chunk;
    uint32_t _chunkNum;
    uint32_t _chunkSize;

};


#endif
