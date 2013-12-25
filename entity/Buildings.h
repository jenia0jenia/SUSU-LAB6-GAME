// TODO: castle, barracks, house

/** Интерфейс для всех зданий в игре, обеспечивает универсальное взаимодействие
 * с сооружениями в игре. Параметры такие как принаддлежность к фракции и т.д.
 *
 * Author: Insality */

#include "Entity.h"

class Buildings: public Entity {
public:
	Buildings();
	virtual ~Buildings();
};
