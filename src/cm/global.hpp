/*
 * global.hpp
 *
 *  Created on: Apr 8, 2014
 *      Author: cv
 */

#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

#include <string>
#include <stdint.h>
#include <vector>
#include "cv.h"

#define nullptr 0

#include "log/logging.hpp"

typedef char char_t;
typedef float float_t;
typedef bool bool_t;

namespace GBL {

typedef cv::Mat Image_t;
typedef const cv::InputArray InputImage_t;
typedef cv::OutputArray OutputImage_t;

typedef cv::Mat Frame_t;

typedef cv::KeyPoint KeyPoint_t;
typedef std::vector<KeyPoint_t> KeyPointCollection_t;

typedef cv::Mat Descriptor_t;

typedef cv::DMatch Match_t;
typedef std::vector<Match_t> MatchCollection_t;

typedef enum cmRetCodes {
	RESULT_SUCCESS,
	RESULT_FAILURE
} CmRetCode_t;

typedef struct point {
	uint32_t x;
	uint32_t y;
} Point_t;

typedef struct displacement {
	int32_t sequenceNo;
	int32_t x;
	int32_t y;
} Displacement_t;

const uint16_t maxFilenameLength = 256;
#if LOG_SEVERITY >= LEVEL_DEBUG
const bool drawResults_b = true;
#else
const bool drawResults_b = false;
#endif

typedef struct DescriptorContainer {
	uint32_t sequenceNo;
	bool valid;
	bool ready;
	GBL::Descriptor_t descriptor;
	GBL::KeyPointCollection_t keypoints;

	DescriptorContainer() {
		valid = false;
		ready = false;
	}
} DescriptorContainer_t;

typedef struct MatchesContainer {
	bool valid;
	GBL::MatchCollection_t matches;
	MatchesContainer() {
		valid = false;
	}
} MatchesContainer_t;

}

#endif /* GLOBAL_HPP_ */