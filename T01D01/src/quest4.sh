ps | grep ai_door_control.sh | grep -v grep | awk '{print $1}' | xargs kill
