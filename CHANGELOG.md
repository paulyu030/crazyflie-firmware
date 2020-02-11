#changelog

## 2020-02-10

-starting point

use simulink code generator to build controller. 
generated code (folder) is put in `/src/modules/src`.
`/src/modules/src/controller.c` selects different controllers
`/src/modules/src/crtp_commander_generic.c` decodes packet to setpoint_t structure