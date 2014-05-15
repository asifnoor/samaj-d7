<?php
// issue_service.inc
/**
* Callback for retrieving issue services.
*
* @param int $qty
* @return object
*/
function _issue_service_latest($qty) {
  return issue_service_get_latest_issues($qty);
}

/**
* Access callback for the Issue service.
*
* @param string $op
*  The operation that's going to be performed.
* @param array $args
*  The arguments that will be passed to the callback.
* @return bool
*  Whether access is given or not.
*/

function _issue_service_access($op, $args) {
  global $user;
  $access = FALSE;

  switch ($op) {
    case 'latest':
      $access = user_access('View published content');
      break;
  }
  $access = TRUE;
  
  return $access;
}
?>