package com.netbil.easyar_flutter

import android.content.Context
import android.graphics.Color
import android.util.TypedValue
import android.view.Gravity
import android.view.View
import android.widget.FrameLayout
import android.widget.TextView
import io.flutter.plugin.common.BinaryMessenger
import io.flutter.plugin.platform.PlatformView

/**
 * PlatformView do EasyAR no Android.
 *
 * Fase 1 (atual): exibe um [FrameLayout] preto com texto centralizado.
 * Parametros do Dart (`senseKey`, `referenceImageAsset`, etc.) chegam
 * em [params] mas nao sao usados ainda.
 *
 * Fase 2: substituir o FrameLayout por um `GLSurfaceView` com EGL3
 * customizado (ver sample `HelloARKotlin/GLView.kt`), inicializar
 * `cn.easyar.Engine.initialize(context, senseKey)` e instanciar o
 * pipeline de camera + tracker.
 */
class EasyArView(
    context: Context,
    @Suppress("UNUSED_PARAMETER") viewId: Int,
    params: Map<String, Any?>,
    @Suppress("UNUSED_PARAMETER") messenger: BinaryMessenger,
) : PlatformView {

    private val container: FrameLayout = FrameLayout(context).apply {
        setBackgroundColor(Color.BLACK)

        val title = TextView(context).apply {
            setTextColor(Color.WHITE)
            setTextSize(TypedValue.COMPLEX_UNIT_SP, 18f)
            text = "EasyAR — Fase 1"
        }
        val subtitle = TextView(context).apply {
            setTextColor(Color.LTGRAY)
            setTextSize(TypedValue.COMPLEX_UNIT_SP, 14f)
            text = buildString {
                append("Ponte Flutter <-> nativo OK\n")
                append("Asset: ${params["referenceImageAsset"] ?: "?"}\n")
                append("Proxima fase: camera + detecao")
            }
            gravity = Gravity.CENTER
            setPadding(32, 16, 32, 16)
        }

        val inner = android.widget.LinearLayout(context).apply {
            orientation = android.widget.LinearLayout.VERTICAL
            gravity = Gravity.CENTER
            addView(title, FrameLayout.LayoutParams(
                FrameLayout.LayoutParams.WRAP_CONTENT,
                FrameLayout.LayoutParams.WRAP_CONTENT,
            ).also { it.gravity = Gravity.CENTER })
            addView(subtitle)
        }
        addView(inner, FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.MATCH_PARENT,
            FrameLayout.LayoutParams.MATCH_PARENT,
        ).also { it.gravity = Gravity.CENTER })
    }

    override fun getView(): View = container

    override fun dispose() {
        // Fase 2: liberar engine EasyAR + GLView.
    }
}
