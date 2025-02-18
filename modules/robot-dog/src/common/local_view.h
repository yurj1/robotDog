/**
 * @file    local_view.h
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include "modules/common/interface/chassis.hpp"
#include "modules/common/interface/events.hpp"
#include "modules/common/interface/obu_cmd_msg.hpp"

/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena
{
  namespace function
  {
    struct LocalView
    {
      athena::interface::Chassis chassis_;
      athena::interface::Events events_;
      athena::interface::ObuCmdMsg obu_cmd_msg_input_;
    };
  } // namespace function
} // namespace athena
