import unittest
import mysort


class MySortTest(unittest.TestCase):
    def test_bubblesort(self):
        l = [1, 6, 4, 2, 5, 3]

        self.assertEqual(
            [1, 2, 3, 4, 5, 6],
            mysort.bubblesort(l)
        )
        self.assertEqual(
            [1, 6, 4, 2, 5, 3],
            l
        )


def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.makeSuite(MySortTest))
    return suite
