
void	sort_few(t_table *table)
{
	table->a = get_head(table->a);
	if (table->a->elem > table->a->next->elem)
		table->a = sa(table->a);
}