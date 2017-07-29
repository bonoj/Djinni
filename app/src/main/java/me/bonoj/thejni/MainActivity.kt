package me.bonoj.thejni

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import me.bonoj.thejni.data.Lamp
import me.bonoj.thejni.data.MeshData

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val meshData = MeshData(7)
        val vertexCoords = getMemberFieldFromNative(meshData)

        Log.i("DJINNI", vertexCoords.toString())


        val lamp = Lamp(2, 5, 1)
        val lampSize = getSizeFieldFromLamp(lamp)

        Log.i("DJINNI", lampSize.toString())

        val stuffFromJNI = stringFromJNI() + "\n" +
                anotherStringFromJNI() + "\n" +
                intFromJNI() + "\n" +
                vertexCoords.toString() + "\n" +
                lampSize.toString()

        Log.i("DJINNI", stuffFromJNI)

        sample_text.text = stuffFromJNI
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String
    external fun anotherStringFromJNI(): String
    external fun intFromJNI(): Int

    external fun getMemberFieldFromNative(obj: MeshData): Float
    external fun getSizeFieldFromLamp(obj: Lamp): Int

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
