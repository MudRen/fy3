// 盐
inherit ITEM;
void create()
{
    set_name( "盐巴", ({ "yan","yanba","salt"}) );
    set("unit", "块");
	set("value" , 10);
    set("long","
这是一块上好的盐巴。
\n");
    set_weight(5);
}
