#py from parse_interfaces import *
#py interfaces = parse_interfaces(pycpp.params['interfaces_file'])
#py for interface_name, interface in interfaces.items():
#py if interface.tag == 'action':
    else if(in->actionType == "`interface.full_name`")
    {
        auto handle_goal_cb = [=] (const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const `interface.goal.cpp_type`> goal) -> rclcpp_action::GoalResponse
        {

            return ros_action_callback__handle_goal__`interface.goal.cpp_type_normalized`(in->_scriptID, in->handleGoalCallback.c_str(), uuid, goal.get(), actionServerProxy);
        };
        auto handle_cancel_cb = [=] (const std::shared_ptr< rclcpp_action::ServerGoalHandle<`interface.cpp_type`> > goal_handle) -> rclcpp_action::CancelResponse
        {
            return ros_action_callback__handle_cancel__`interface.goal.cpp_type_normalized`(in->_scriptID, in->handleCancelCallback.c_str(), goal_handle->get_goal_id(), goal_handle->get_goal().get(), actionServerProxy);
        };
        auto handle_accepted_cb = [=] (const std::shared_ptr< rclcpp_action::ServerGoalHandle<`interface.cpp_type`> > goal_handle)
        {
            ros_action_callback__handle_accepted__`interface.goal.cpp_type_normalized`(in->_scriptID, in->handleAcceptedCallback.c_str(), goal_handle->get_goal_id(), goal_handle->get_goal().get(), actionServerProxy);
        };
        actionServerProxy->action_server = rclcpp_action::create_server<`interface.cpp_type`>(node, in->actionName, handle_goal_cb, handle_cancel_cb, handle_accepted_cb);
    }
#py endif
#py endfor
