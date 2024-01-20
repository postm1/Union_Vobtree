// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	
	//get recursive children
	void GetChildrenPFX(zCTree<zCVob>* node, zCVob* pickedVob, zCVob* globalParent)
	{
		zCVob* vob = node->GetData();

		if (vob)
		{
			zCParticleFX* m_pPfx = vob->CastTo<zCParticleFX>();

			if (m_pPfx)
			{
				m_pPfx->StopEmitterOutput();
				m_pPfx->m_bVisualNeverDies = false;

			}

			auto visual = vob->GetVisual();

			if (visual)
			{
				if (auto part = visual->CastTo<zCParticleFX>())
				{
					part->StopEmitterOutput();
					part->m_bVisualNeverDies = false;
				}

			}

		}

		node = node->GetFirstChild();

		while (node != NULL)
		{
			GetChildrenPFX(node, pickedVob, globalParent);
			node = node->GetNextChild();
		}
	}

	// checks if level is loaded
	bool IsWorldReadyOrLoaded(bool checkPlayer = true)
	{
		bool result = false;

		bool playerCheck = true;

		if (checkPlayer)
		{
			if (!player || !player->GetHomeWorld())
			{
				playerCheck = false;
			}
		}

		if (playerCheck && ogame && ogame->GetWorld())
		{
			result = true;
		}

		return result;
	}

	// inserts vobtree into world tree

	void InsertVobTree(zSTRING path, zSTRING parentName) {

		zoptions->ChangeDir(DIR_WORLD);

		zCWorld* world = ogame->GetWorld();

		if (world)
		{
			zCVob* pParent = NULL;

			if (parentName.Length() > 0)
			{
				pParent = world->SearchVobByName(parentName);
			}

			zCVob* vob = ogame->GetWorld()->MergeVobSubtree(path, pParent, zCWorld::zWLD_LOAD_MERGE_ADD);

			if (auto wpVob = dynamic_cast<zCVobWaypoint*>(vob))
			{
				auto wp = zfactory->CreateWaypoint();
				wp->Init(wpVob);
				wp->SetName(wpVob->objectName);
				ogame->GetWorld()->wayNet->InsertWaypoint(wp);

				//Message::Box("wp: " + wpVob->objectName);
			}
		}
	}
}