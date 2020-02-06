#include "filler.h"

void	wipe_piece(t_piece **piece)
{
	wipe_mstr((*piece)->mstr);
	*piece = NULL;
}
