package me.bonoj.thejni

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*
import me.bonoj.thejni.data.Lamp
import me.bonoj.thejni.data.MeshData

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method

        val stuffFromJNI = stringFromJNI() + "\n" + anotherStringFromJNI() + "\n" + intFromJNI()

        val lamp = Lamp(2, 5, 1)
        val meshData = MeshData(7);

        val vertexCoords = getMemberFieldFromNative(meshData)


        sample_text.text = vertexCoords.toString()
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String
    external fun anotherStringFromJNI(): String
    external fun intFromJNI(): Int

    external fun getMemberFieldFromNative(obj: MeshData): Float

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
