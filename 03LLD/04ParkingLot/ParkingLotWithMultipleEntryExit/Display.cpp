#include "Display.hxx"

Display::Display(string id)
{
	displayId = id;
}

void Display::configDisplay(ParkingSlot slot)
{
	slots.push_back(slot);
}

void Display::updateParkingDisplaySlotStaus(ParkingSlot slot)
{
	for (auto &it : slots) {
		if (it.getParkingSlotNumber() == slot.getParkingSlotNumber()) {
			it.setparkingSlotStatus(slot.getParkingSlotStatus());
			break;
		}
	}
}

void Display::showParkingDisplayInfo()
{
	cout << "\n\n***** Display Id : " << displayId << " *****\n\n";
	for (auto it : slots) {
		cout << it.getParkingSlotNumber() << " : " << it.getParkingSlotType() << " : " << it.getParkingSlotStatus() << endl;
	}
	cout << "\n\n -------------------- \n\n";
}
