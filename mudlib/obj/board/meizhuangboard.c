//lu's 桃花弟子留言板
inherit BULLETIN_BOARD;

void create()
{
	set_name("梅花录",({"board"}));
	set("location","/d/meizhuang/caoting");
	set("board_id","meizhuangboard");
        set("long",
	"梅庄大庄子亲自打制的牌匾，梅庄弟子可在上面发表见解。\n");
        setup();
	set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
