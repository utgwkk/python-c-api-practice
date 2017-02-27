import unittest
import mysort


class MySortTest(unittest.TestCase):
    def test_bubblesort(self):
        self.assertEqual(
            [1, 2, 3, 4, 5, 6],
            mysort.bubblesort([1, 6, 4, 2, 5, 3])
        )


def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.makeSuite(MySortTest))
    return suite
