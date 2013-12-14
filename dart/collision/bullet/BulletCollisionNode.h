/*
 * Copyright (c) 2013, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Jeongseok Lee <jslee02@gmail.com>
 *
 * Geoorgia Tech Graphics Lab and Humanoid Robotics Lab
 *
 * Directed by Prof. C. Karen Liu and Prof. Mike Stilman
 * <karenliu@cc.gatech.edu> <mstilman@cc.gatech.edu>
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DART_COLLISION_BULLET_BULLETCOLLISIONNODE_H_
#define DART_COLLISION_BULLET_BULLETCOLLISIONNODE_H_

#include <vector>

#include <Eigen/Dense>

#include "dart/dynamics/Shape.h"
#include "dart/collision/CollisionNode.h"
#include "dart/collision/bullet/btBulletCollisionCommon.h"

namespace dart {
namespace dynamics {
class BodyNode;
}  // namespace dynamics
}  // namespace dart

namespace dart {
namespace collision {

class BulletCollisionNode;
class BulletCollisionDetector;

struct btUserData {
    dynamics::BodyNode* bodyNode;
    dynamics::Shape* shape;
    BulletCollisionNode* btCollNode;
    BulletCollisionDetector* btCollDet;
};

/// @brief
class BulletCollisionNode : public CollisionNode {
public:
    /// @brief
    explicit BulletCollisionNode(dynamics::BodyNode* _bodyNode);

    /// @brief
    virtual ~BulletCollisionNode();

    /// @brief Update transformation of all the bullet collision objects.
    void updateBTCollisionObjects();

    /// @brief
    int getNumBTCollisionObjects() const;

    /// @brief
    btCollisionObject* getBTCollisionObject(int _i);

private:
    /// @brief
    std::vector<btCollisionObject*> mbtCollsionObjects;
};

}  // namespace collision
}  // namespace dart

#endif  // DART_COLLISION_BULLET_BULLETCOLLISIONNODE_H_