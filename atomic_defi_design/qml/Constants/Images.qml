pragma Singleton
import QtQuick 2.15

QtObject {
	readonly property string assets_path: "qrc:///"
    readonly property string image_path: assets_path + "atomic_defi_design/assets/images/tutorial/"

    // Image list
    readonly property string tour_step1: images + "step1.png"
    readonly property string tour_step2: images + "step2.png"
    readonly property string tour_step3: images + "step3.png"
}