//嵩山派留言板 by xxy 6/14/99
inherit BULLETIN_BOARD;

void create()
{
set_name("千年神木碑",({"board"}));
set("location","/d/songshan/chanyuan");
set("board_id","songshan_board");
        set("long",
"这颗千年的神木已经枯萎而死,正中的一段被人剥掉了树皮.\n
粗可数十人合抱的神木是天然的留言板.(help board)\n");
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
