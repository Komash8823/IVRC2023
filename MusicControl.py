from appscript import app


class MusicControl(object):
    """
    AppleScriptを利用して、Musicアプリをコントロールするクラス
    注意：MacOSに依存する
    """
    def __init__(self):
        super().__init__()
        self.app = app('Music')
        self.app.run()

    def pause(self):
        """
        再生を一時停止する
        :return:
        """
        self.app.pause()

    def play(self):
        """
        再生
        :return:
        """
        self.app.play()

    def stop(self):
        """
        停止
        :return:
        """
        self.app.stop()

    def next_track(self):
        """
        次の曲へ飛ぶ
        :return:
        """
        self.app.next_track()

    @property
    def sound_volume(self) -> int:
        """
        ボリュームを0〜100の範囲で返す
        :return: 
        """
        return self.app.sound_volume.get()

    @sound_volume.setter
    def sound_volume(self, volume: int):
        """
        ボリュームを0〜100の範囲で設定する
        :return: 
        """
        self.app.sound_volume.set(volume)